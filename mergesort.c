// Initial code: https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm
#include <stdio.h>
#include "constants.h"
#include <sys/time.h>

// int a[11] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[FILESIZE-1];
int numArray[FILESIZE];

void merging(int low, int mid, int high)
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

void sort(int low, int high)
{
    int mid;

    if (low < high){
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merging(low, mid, high);
    }
    else{
        return;
    }
}

int main(){
    struct timeval tvalBefore, tvalAfter; // Timer to time program
    gettimeofday (&tvalBefore, NULL);
    double timeBef = tvalBefore.tv_sec+(tvalBefore.tv_usec/1000000.0);

    FILE *itemFile;
    itemFile = fopen("items.txt","r"); // File with ints
    size_t ret_code = fread(numArray, sizeof *numArray, FILESIZE, itemFile); // reads an array of int
    if(ret_code == FILESIZE) {
        puts("Array read successfully\n");
        // for(int n = 0; n < 10; ++n) {
        //     printf("%i ", numArray[n]);
        // }
        // putchar('\n');
    } else { // error handling
       if (feof(itemFile))
          printf("Error reading file: unexpected end of file\n");
       else if (ferror(itemFile)) {
           perror("Error reading file");
       }
    }
 
    
    printf("First 10 elements before sorting:\n");
    for (int i = 0; i <= 10; i++){
        printf("%d ", numArray[i]);
    }

    sort(0, FILESIZE);
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