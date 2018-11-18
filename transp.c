#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
     if(argc != 3){
          fprintf(stderr, "Wrong number of command-line arguments.\nUsage: %s <width of input matrix> <width of block>\n", argv[0]);
          return -1;
     }

     int inputWidth = atoi(argv[1]);
     int blockWidth = atoi(argv[2]);

     float *inMatrix;
     if((inMatrix = (float*)malloc(inputWidth * sizeof(float))) == NULL){
          fprintf(stderr, "malloc failed\n");
          return -1;
     }

     float *outMatrix;
     if((outMatrix = (float*)malloc(inputWidth * sizeof(float))) == NULL){
          fprintf(stderr, "malloc failed\n");
          return -1;
     }

     for(int i = 0;  i < inputWidth;  i++){
          inMatrix[i] = ((float)rand() / RAND_MAX) * 200 - 100;
          printf("%f\n", inMatrix[i]);
     }

     free(inMatrix);
     free(outMatrix);
}
