//http://en.cppreference.com/w/c/io/fread for fread
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include "constants.h"

int main() {

    FILE *itemFile;
    itemFile = fopen("items.txt","r"); // File with ints
    bool found = false;
    srand(time(NULL));
    int inputNum  = rand()%10000000;
    int *numArray;
    numArray=(int *)malloc(sizeof(int)*FILESIZE);

    size_t ret_code = fread(numArray, sizeof *numArray, FILESIZE, itemFile); // reads an array of doubles
    struct timeval tvalBefore, tvalAfter; // Timer to time program
    gettimeofday (&tvalBefore, NULL);
    double timeBef = tvalBefore.tv_sec+(tvalBefore.tv_usec/1000000.0);

    if(ret_code == FILESIZE) {
        for(int i=0; i<FILESIZE;i++){ // Run through file
            if(numArray[i]==inputNum){
                printf("Found %d in file on line %d\n",inputNum,i);
                found=true;
            }
	    }
    } 
    else { // error handling
       if (feof(itemFile))
          printf("Error reading test.bin: unexpected end of file\n");
       else if (ferror(itemFile)) {
           perror("Error reading test.bin");
       }
    }
    
    if(!found){
        printf("Number not found\n");
    }
    fclose(itemFile);

    gettimeofday (&tvalAfter, NULL); // End of timer
    double timeAft = tvalAfter.tv_sec+(tvalAfter.tv_usec/1000000.0);
    printf("Search runtime: %.4f seconds\n",timeAft-timeBef);
}