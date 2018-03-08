//https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm for fread
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <omp.h>
#include "constants.h"


int main(int argc, const char * argv[]) {

    struct timeval tvalBefore, tvalAfter; // Timer to time program
    gettimeofday (&tvalBefore, NULL);
    double timeBef = tvalBefore.tv_sec+(tvalBefore.tv_usec/1000000.0);
    
    FILE *itemFile;
    itemFile = fopen("items.txt","r"); // File with ints
    bool found = false;
    int inputNum;
    printf("Enter the number to find\n");
    scanf("%d",&inputNum);

    #pragma omp parallel for // Openmp to parallelise
        for(int i=0; i<FILESIZE;i++){ // Run through file
            int number;
            
            fscanf(itemFile, "%d", &number); // Read in integer at i index. Reads in one int at a time and compares
            if(number==inputNum){
                printf("Found %d in file on line %d\n",inputNum,i);
                found=true;
            }
	    }
    if(!found){
        printf("Number not found\n");
    }
    fclose(itemFile);

    gettimeofday (&tvalAfter, NULL); // End of timer
    double timeAft = tvalAfter.tv_sec+(tvalAfter.tv_usec/1000000.0);
    printf("Program runtime: %.4f seconds\n",timeAft-timeBef);
}

