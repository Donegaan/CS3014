// Initial code: https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include <sys/time.h>



void merging(int low, int mid, int high,int numArray[],int b[])
{
    int l1, l2, i;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++){
        if (numArray[l1] <= numArray[l2]){
            b[i] = numArray[l1++];
        }
        else{
            b[i] = numArray[l2++];
        }
    }

    while (l1 <= mid){
        b[i++] = numArray[l1++];
    }

    while (l2 <= high){
        b[i++] = numArray[l2++];
    }

    for (i = low; i <= high; i++){
        numArray[i] = b[i];
    }
}

void sort(int low, int high,int numArray[],int b[])
{
    int mid;

    if (low < high){
        mid = (low + high) / 2;
        sort(low, mid,numArray,b);
        sort(mid + 1, high,numArray,b);
        merging(low, mid, high,numArray,b);
    }
}

int main(){
    struct timeval tvalBefore, tvalAfter; // Timer to time program
    gettimeofday (&tvalBefore, NULL);
    double timeBef = tvalBefore.tv_sec+(tvalBefore.tv_usec/1000000.0);

    int *numArray;
    numArray=(int *)malloc(sizeof(int)*FILESIZE); // Arrays for merge
    int *b;
    b=(int *)malloc(sizeof(int)*FILESIZE-1);

    FILE *itemFile;
    itemFile = fopen("items.txt","r"); // File with ints
    
    size_t ret_code = fread(numArray, sizeof *numArray, FILESIZE, itemFile); // reads an array of int
    if(ret_code == FILESIZE) {
        puts("Array read successfully\n");
    } else { // error handling
       if (feof(itemFile))
          printf("Error reading file: unexpected end of file\n");
       else if (ferror(itemFile)) {
           perror("Error reading file");
       }
    }
 
    
    printf("First 10 elements before sorting:\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", numArray[i]);
    }

    sort(0, FILESIZE,numArray,b);
    // Will write sorted list back to file
    printf("\n\nFirst 10 elements after sorting:\n");

    for (int i = 0; i < 10; i++){
        printf("%d ", numArray[i]);
    }
    FILE *sortFile = fopen("serialSortOut.txt","w"); // Write sorted array to file
    fwrite(numArray,sizeof *numArray,FILESIZE,sortFile);

    fclose(sortFile); // Close file streams
    fclose(itemFile);

    gettimeofday (&tvalAfter, NULL); // End of timer
    double timeAft = tvalAfter.tv_sec+(tvalAfter.tv_usec/1000000.0);
    printf("\n\nProgram runtime: %.4f seconds\n",timeAft-timeBef);
}