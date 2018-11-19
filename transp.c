#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv){
     struct timeval start;
     gettimeofday(&start, 0);

     for(int repeat = 0;  repeat < 1; repeat++){
          if(argc != 3){
               fprintf(stderr, "Wrong number of command-line arguments.\nUsage: %s <width of input matrix> <width of block>\n", argv[0]);
               return -1;
          }

          int inputWidth = atoi(argv[1]); //N
          int blockWidth = atoi(argv[2]);
          printf("inputWidth: %d\tblockWidth: %d\n", inputWidth, blockWidth);

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
               //printf("%f\n", inMatrix[i]);
          }

          for(int iBlock = 0;  iBlock < inputWidth;  iBlock += blockWidth){
               for(int jBlock = 0;  jBlock < inputWidth;  jBlock += blockWidth){
                    //printf("i: %d\tj: %d\n", iBlock, jBlock);
                    for(int i = 0;  i < blockWidth;  i++){
                         for(int j = 0;  j < blockWidth;  j++){
                              //inMatrix[iBlock * i * inputWidth  +  j * jBlock]
                              printf("%d\n", (iBlock * inputWidth) + (i * inputWidth)  +  (j + jBlock));
                         }
                         printf("\n");
                    }
                    printf("new row\n");
               }
               printf("\n\n");
          }
          // for(int i = 0;  i < inputWidth / blockWidth;  i++){
          //      for(int j = 0;  j < blockWidth * i;  j++){
          //           outMatrix[] = inMatrix[i*inputWidth + j]
          //      }
          // }
          free(inMatrix);
          free(outMatrix);
     }

     struct timeval end;
     gettimeofday(&end, 0);

     long startSec       = start.tv_sec;
     long startSubSec    = start.tv_usec;
     long endSec         = end.tv_sec;
     long endSubSec      = end.tv_usec;
     long totalTime      = (endSec * 1000000 + endSubSec) - (startSec * 1000000 + startSubSec);
     //printf("%ld\n", totalTime);
}
