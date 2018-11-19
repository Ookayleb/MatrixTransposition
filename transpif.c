//Caleb Choy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv){
     struct timeval start;
     gettimeofday(&start, 0);

     for(int repeat = 0;  repeat < 1; repeat++){
          if(argc != 4){
               fprintf(stderr, "Wrong number of command-line arguments.\nUsage: %s <height of input matrix> <width of input matrix> <width of block>\n", argv[0]);
               return -1;
          }

          int inputHeight     = atoi(argv[1]); //N
          int inputWidth      = atoi(argv[2]);
          int blockWidth      = atoi(argv[3]);
          int arraySize       = inputHeight * inputWidth;
          int arrayFloatSize  = arraySize * sizeof(float);
          // printf("inputWidth: %d\tblockWidth: %d\n", inputWidth, blockWidth);

          float *inMatrix;
          if((inMatrix = (float*)malloc(arrayFloatSize)) == NULL){
               fprintf(stderr, "malloc failed\n");
               return -1;
          }

          float *outMatrix;
          if((outMatrix = (float*)malloc(arrayFloatSize)) == NULL){
               fprintf(stderr, "malloc failed\n");
               return -1;
          }

          for(int i = 0;  i < arraySize;  i++){
               inMatrix[i] = i;//((float)rand() / RAND_MAX) * 200 - 100;
               // printf("%f\t", inMatrix[i]);
               // if((i + 1) % inputWidth == 0){
               //      printf("\n");
               // }
          }

          // printf("done done\n\n\n");
          for(int iBlock = 0;  iBlock < inputHeight;  iBlock += blockWidth){
               for(int jBlock = 0;  jBlock < inputWidth;  jBlock += blockWidth){
                    // printf("ini: %d\tinj: %d\n", iBlock, jBlock);
                    // printf("outi: %d\touti: %d\n", jBlock, iBlock);
                    for(int i = 0;  i < blockWidth;  i++){
                         for(int j = 0;  j < blockWidth;  j++){
                              int inIndex    = (iBlock * inputWidth) + (i * inputWidth)  +  (j + jBlock);
                              int outIndex   = (jBlock * inputWidth) + (j * inputWidth)  +  (i + iBlock);
                              //outMatrix[outIndex] = inMatrix[inIndex];
                              printf("in: %d\n", inIndex);//(iBlock * inputWidth) + (i * inputWidth)  +  (j + jBlock));
                              // printf("out: %d\n", outIndex);//(jBlock * inputWidth) + (j * inputWidth)  +  (i + iBlock));

                         }
                         printf("\n");
                    }
                    printf("new row\n");
               }
               printf("\n\n");
          }
          // for(int i = 0;  i < inputWidth * inputWidth; i++){
          //      printf("%f\t", outMatrix[i]);
          //      if((i + 1) % inputWidth == 0){
          //           printf("\n");
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
     printf("%ld\n", totalTime);
}
