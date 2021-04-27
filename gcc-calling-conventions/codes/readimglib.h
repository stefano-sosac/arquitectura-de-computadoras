/* This codes are taken from the mpsidlib library from P. Rodriguez - PUCP */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define err_info(msg, args...)                                                          \
      printf("file: %s,\tfunction: %s, \tline: %d \n", __FILE__, __func__, __LINE__);   \
      printf(msg, ## args)


void read_headppm(char *filename, int *Nrows, int *Ncols, char *type);
void read_ppm2uchar(char *filename, unsigned char *In, int Ndata, char *type);
void write_uchar2ppm(char *filename, unsigned char *In, int Nrows, int Ncols, char *type);

void read_headppm(char *filename, int *Nrows, int *Ncols, char *type)
{
/* Reads the header of a PPM/PGM file, type P5/P6 (raw) or P2/P3 (ascii) */

   FILE *fp;

   char val[256];


       fp = fopen(filename,"r");
       if(fp == NULL) {

          err_info("error opening file : %s\n",filename);
          exit(1);
       }

       fscanf(fp,"%s\n",val);

       if( strncmp(type,val,2) != 0 ) {

          err_info("not a PPM %s binary file\ntype: %s\n",type, val);
          exit(1);

       }

//The function fgets read until a newline (and also stores it). 
//fscanf with the %s specifier reads until any blank space and doesn't store it...
       fscanf(fp,"%s\n",val);
       while( strncmp("#",val,1) == 0) {

         fgets(val, 256, fp);
         fscanf(fp,"%s\n",val);
       }

       *Ncols = atoi(val);

       fscanf(fp,"%s\n",val);
       *Nrows = atoi(val);

       fscanf(fp,"%s\n",val);
       if( strncmp("255",val,3) != 0 ) {
          err_info("PPM not using a 255 scale\nscale: %s\n",val);
       }
       fclose(fp);
}

void read_ppm2uchar(char *filename, unsigned char *In, int Ndata, char *type)
{/* reads a P5/P6 PGM/PPM file */

   FILE *fp;

   char val[256];

       fp = fopen(filename,"r");
       if(fp == NULL) {

          err_info("error opening file : %s\n",filename);
          exit(1);
       }

       fscanf(fp,"%s\n",val);

       if( strncmp(type,val,2) != 0 ) {

          err_info("not a PPM %s binary file\ntype: %s\n",type, val);
          exit(1);

       }


       fscanf(fp,"%s\n",val);
       while( strncmp("#",val,1) == 0) {

         fgets(val, 256, fp);
         fscanf(fp,"%s\n",val);
       }


       fscanf(fp,"%s\n",val);
       fscanf(fp,"%s\n",val);
       
       if( strncmp("255",val,3) != 0 ) {

          err_info("not expected... aborting\nscale: %s\n",val);
          exit(1);
       }


       fread(In, sizeof(char), Ndata, fp);

       fclose(fp);

}

void write_uchar2ppm(char *filename, unsigned char *In, int Nrows, int Ncols, char *type)
{/* reads a P5/P6 PGM/PPM file */

  FILE *fp;
  int Ndata = Nrows * Ncols;
  

      if( strncmp(type,"P5",2) != 0 ) {

         err_info("not a PPM %s binary file\ntype: P5\n",type);
         return;

      }
          
      fp = fopen(filename,"w");
      if(fp == NULL) {

         err_info("error opening file : %s\n",filename);
         return;
      }

      /* print type*/
      fprintf(fp,"%s\n",type);
      
      /* print comment */
      fprintf(fp,"#\n");

      /* print Ncols & Nrows */
      fprintf(fp,"%d %d\n",Ncols, Nrows);
      
      /* print no. of grayscales */
      fprintf(fp,"255\n");

      /* write data */
      fwrite(In, sizeof(char), Ndata, fp);

      fclose(fp);

  return;
}

int save_data(int *data, int N, char *fname)
{
  FILE * fid;

    fid = fopen(fname, "w");
    fwrite(data, sizeof(int), N, fid);
    fclose(fid);

   return(0);

}