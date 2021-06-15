/*
Original code from Toby Speight
https://codereview.stackexchange.com/questions/175113/multithreaded-matrix-multiplication-on-unix-in-c
Adapted for OAC - 2021-1

gcc -pthread AxBpthreads.c -o AxBpthreads
./AxBpthreads

To change number of threads for experiments, change the line
#define NTHREADS X
*/

//matrix.h

#include <stdlib.h>

#define NTHREADS 8

typedef struct matrix_t {
    size_t  m_rows;
    size_t  m_cols;
    double* m_data;
} matrix_t;

matrix_t* matrix_t_alloc(size_t rows, size_t cols);
void      matrix_t_init(matrix_t* matrix, size_t rows, size_t cols);
void      matrix_t_clear(matrix_t* matrix);
void      matrix_t_free(matrix_t* matrix);

double    matrix_t_get(matrix_t const* matrix, size_t x, size_t y);
void      matrix_t_set(matrix_t* matrix, size_t x, size_t y, double value);
matrix_t* matrix_t_copy(matrix_t const* matrix);


//matrix_algorithm.h


matrix_t* matrix_t_multiply(matrix_t const* matrix1, matrix_t const* matrix2);
matrix_t* matrix_t_multiply_parallel(matrix_t const* matrix1, matrix_t const* matrix2);
void      matrix_t_print(matrix_t const* matrix);


//matrix.c

#include <stdlib.h>
#include <string.h>

static size_t data_index(matrix_t const* matrix, size_t x, size_t y)
{
    return y * matrix->m_cols + x;
}

matrix_t* matrix_t_alloc(size_t rows, size_t cols)
{
    matrix_t *const m = malloc(sizeof *m);
    if (!m) {
        return m;
    }
    matrix_t_init(m, rows, cols);
    if (!m->m_data) {
        free(m);
        return NULL;
    }
    return m;
}

void matrix_t_init(matrix_t* matrix, size_t rows, size_t cols)
{
    matrix->m_data = malloc(sizeof *matrix->m_data * rows * cols);
    if (matrix->m_data) {
        matrix->m_rows = rows;
        matrix->m_cols = cols;
    } else {
        matrix->m_rows = 0;
        matrix->m_cols = 0;
    }
}

void matrix_t_clear(matrix_t* matrix)
{
    free(matrix->m_data);
    matrix->m_rows = 0;
    matrix->m_cols = 0;
}

void matrix_t_free(matrix_t* matrix)
{
    matrix_t_clear(matrix);
    free(matrix);
}

double matrix_t_get(matrix_t const* matrix, size_t x, size_t y)
{
    return matrix->m_data[data_index(matrix, x, y)];
}

void matrix_t_set(matrix_t* matrix, size_t x, size_t y, double value)
{
    matrix->m_data[data_index(matrix, x, y)] = value;
}

matrix_t* matrix_t_copy(matrix_t const* matrix)
{
    size_t data_len = sizeof *matrix->m_data * matrix->m_rows * matrix->m_cols;
    matrix_t* copy = matrix_t_alloc(matrix->m_rows, matrix->m_cols);
    if (copy) {
        memcpy(copy->m_data, matrix->m_data, data_len);
    }
    return copy;
}

//matrix_algorithm.c

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static size_t max_size_t(size_t x, size_t y)
{
    return x > y ? x : y;
}
static size_t min_size_t(size_t x, size_t y)
{
    return x < y ? x : y;
}

matrix_t* matrix_t_multiply(matrix_t const* matrix1, matrix_t const* matrix2)
{
    if (!matrix1 || !matrix2) {
        return NULL;
    }

    if (!matrix1->m_data || !matrix2->m_data) {
        return NULL;
    }

    if (matrix1->m_cols != matrix2->m_rows) {
        return NULL;
    }

    matrix_t *const result = matrix_t_alloc(matrix1->m_rows, matrix2->m_cols);

    for (size_t y = 0; y != matrix1->m_rows; ++y) {
        for (size_t x = 0; x != matrix2->m_cols; ++x) {
            double sum = 0.0;

            for (size_t i = 0; i != matrix1->m_cols; ++i) {
                sum += matrix_t_get(matrix1, i, y) *
                    matrix_t_get(matrix2, x, i);
            }

            matrix_t_set(result, x, y, sum);
        }
    }

    return result;
}

static const size_t MINIMUM_THREAD_LOAD = 10 * 1000;

typedef struct thread_info {
    matrix_t const* left_matrix;
    matrix_t const* right_matrix;
    matrix_t* result_matrix;
    size_t    start_row;
    size_t    rows;
    pthread_t thread;
} thread_info;

static void* thread_func(void* arg)
{
    thread_info *const info = arg;

    for (size_t y = info->start_row; y < info->start_row + info->rows; ++y) {
        for (size_t x = 0; x < info->right_matrix->m_cols; ++x) {
            double sum = 0.0;

            for (size_t i = 0; i < info->left_matrix->m_cols; ++i) {
                sum += matrix_t_get(info->left_matrix, i, y) *
                    matrix_t_get(info->right_matrix, x, i);
            }

            matrix_t_set(info->result_matrix, x, y, sum);
        }
    }

    return NULL;
}

matrix_t* matrix_t_multiply_parallel(matrix_t const* left_matrix,
                                     matrix_t const* right_matrix)
{
    size_t const work_load =
        left_matrix->m_rows *
        right_matrix->m_cols *
        right_matrix->m_rows;

    size_t num_threads = (size_t)NTHREADS;//(size_t)sysconf(_SC_NPROCESSORS_ONLN);
    num_threads = min_size_t(num_threads, work_load / MINIMUM_THREAD_LOAD);
    num_threads = min_size_t(num_threads, left_matrix->m_rows);
    num_threads = max_size_t(num_threads, 1);

    if (num_threads == 1) {
        return matrix_t_multiply(left_matrix, right_matrix);
    }

    matrix_t *const result_matrix = matrix_t_alloc(left_matrix->m_rows,
                                                   right_matrix->m_cols);
    if (!result_matrix) {
        return NULL;
    }

    thread_info *threads = calloc(num_threads, sizeof *threads);
    if (!threads) {
        matrix_t_free(result_matrix);
        return NULL;
    }

    const size_t basic_rows_per_thread = left_matrix->m_rows / num_threads;
    for (size_t i = 0, rows_reserved = 0;
         i != num_threads;
         i++, rows_reserved += basic_rows_per_thread)
        {
            threads[i].left_matrix   = left_matrix;
            threads[i].right_matrix  = right_matrix;
            threads[i].result_matrix = result_matrix;
            threads[i].rows          = basic_rows_per_thread;
            threads[i].start_row     = rows_reserved;
        }

    threads[num_threads - 1].rows +=
        left_matrix->m_rows % basic_rows_per_thread;

    /* block 0 will be run in this thread */
    for (size_t i = 1; i < num_threads; ++i) {
        pthread_create(&threads[i].thread,
                       NULL,
                       thread_func,
                       (void*) &threads[i]);
    }

    thread_func((void*) &threads[0]);

    for (size_t i = 1; i < num_threads; ++i) {
        pthread_join(threads[i].thread, NULL);
    }

    free(threads);

    return result_matrix;
}

void matrix_t_print(matrix_t const* matrix)
{
    for (size_t y = 0; y < matrix->m_rows; ++y) {
        for (size_t x = 0; x < matrix->m_cols; ++x) {
            printf("%f ", matrix_t_get(matrix, x, y));
        }

        puts("");
    }
}

//main.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

static matrix_t* create_random_matrix(size_t rows, size_t cols)
{
    matrix_t* m = malloc(sizeof(*m));
    matrix_t_init(m, rows, cols);

    for (size_t x = 0; x < cols; ++x) {
        for (size_t y = 0; y < rows; ++y) {
            matrix_t_set(m, x, y, ((double) rand()) / RAND_MAX);
        }
    }

    return m;
}

static long get_milliseconds_difference(struct timeval *a, struct timeval *b)
{
    return(a->tv_sec - b->tv_sec) * 1000 + (a->tv_usec - b->tv_usec) / 1000;
}

static int matrix_equals(matrix_t const *a, matrix_t const *b)
{
    if (!a || !b) {
        /* treat NULL like NaN, not equal to itself */
        return !b;
    }

    if (a->m_cols != b->m_cols || a->m_rows != b->m_rows) {
        return 0;
    }

    for (size_t y = 0; y < a->m_rows; ++y) {
        for (size_t x = 0; x < a->m_cols; ++x) {
            if (matrix_t_get(a, x, y) != matrix_t_get(b, x, y)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    struct timeval start_time, end_time;

    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    printf("Using random seed = %u\n", seed);

    matrix_t *a = create_random_matrix(1000, 1000);
    matrix_t *b = matrix_t_copy(a);
    if (!a || !b)
        return EXIT_FAILURE;

    gettimeofday(&start_time, NULL);
    matrix_t *ab1 = matrix_t_multiply(a, b);
    gettimeofday(&end_time, NULL);

    if (!ab1)
        return EXIT_FAILURE;

    printf("Single-threaded multiplication in %ld milliseconds.\n",
           get_milliseconds_difference(&end_time, &start_time));

    gettimeofday(&start_time, NULL);
    matrix_t *ab2 = matrix_t_multiply_parallel(a, b);
    gettimeofday(&end_time, NULL);

    if (!ab2)
        return EXIT_FAILURE;

    //printf("%zu-threaded multiplication in %ld milliseconds.\n",
    printf("%d-threaded multiplication in %ld milliseconds.\n",
           NTHREADS/*sysconf(_SC_NPROCESSORS_ONLN)*/,
           get_milliseconds_difference(&end_time, &start_time));

    printf("Algorithms agree: %d\n", matrix_equals(ab1, ab2));

    matrix_t_free(a);
    matrix_t_free(b);
    matrix_t_free(ab1);
    matrix_t_free(ab2);

    return 0;
}
