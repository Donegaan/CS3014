// Initial code: https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm
#include <stdio.h>
#include "constants.h"
#include <sys/time.h>

#define max 10

int a[11] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[10];


void merging(int low, int mid, int high)
{
    int l1, l2, i;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++){
        if (a[l1] <= a[l2]){
            b[i] = a[l1++];
        }
        else{
            b[i] = a[l2++];
        }
    }

    while (l1 <= mid){
        b[i++] = a[l1++];
    }

    while (l2 <= high){
        b[i++] = a[l2++];
    }

    for (i = low; i <= high; i++){
        a[i] = b[i];
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
    // struct timeval tvalBefore, tvalAfter; // Timer to time program
    // gettimeofday (&tvalBefore, NULL);
    // double timeBef = tvalBefore.tv_sec+(tvalBefore.tv_usec/1000000.0);

    int numArray[FILESIZE];
    FILE *itemFile;
    itemFile = fopen("items.txt","r"); // File with ints
    size_t ret_code = fread(numArray, sizeof *numArray, FILESIZE, itemFile); // reads an array of int
    if(ret_code == FILESIZE) {
        puts("Array read successfully, contents: ");
        for(int n = 0; n < 10; ++n) 
            printf("%i ", numArray[n]);
        putchar('\n');
    } else { // error handling
       if (feof(itemFile))
          printf("Error reading test.bin: unexpected end of file\n");
       else if (ferror(itemFile)) {
           perror("Error reading test.bin");
       }
    }
 
    fclose(itemFile);

    // int i;
    // printf("List before sorting\n");
    // for (i = 0; i <= max; i++){
    //     printf("%d ", a[i]);
    // }

    // sort(0, max);
    // // Will write sorted list back to file
    // printf("\nList after sorting\n");

    // for (i = 0; i <= max; i++){
    //     printf("%d ", a[i]);
    // }

    // gettimeofday (&tvalAfter, NULL); // End of timer
    // double timeAft = tvalAfter.tv_sec+(tvalAfter.tv_usec/1000000.0);
    // printf("Program runtime: %.4f seconds\n",timeAft-timeBef);
}