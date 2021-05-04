// gcc -S -O0 -masm=intel stack-heap.c -o stack-heap.s

int hello(){
    int a = 100;
    return a;
}


int main(){
    int a;
    int b = -3;
    int c = 12345;
    int *p = &b;
    int d = hello();
    return 0;
}