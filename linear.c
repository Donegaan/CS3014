//https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm for fread
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "constants.h"

//https://codereview.stackexchange.com/questions/73553/finding-the-size-of-a-file to get file size
// long fsize(FILE *fp) {
//     fseek(fp, 0, SEEK_END);
//     long bytes = ftell(fp);
//     rewind(fp);
//     return bytes;
// }

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
    // int size = sizeof(int);
    // long nmemb = fsize(&itemFile);
    // printf("%d",nmemb);
    for(int i=0; i<FILESIZE;i++){ // Run through file
        int number;
        
        fscanf(itemFile, "%d", &number); // Read in integer
        if(number==inputNum){
            printf("Found %d in file on line %d\n",inputNum,i);
            found=true;
        }
        //fread(buffer, size,nmemb, itemFile);
	}
    if(!found){
        printf("Number not found\n");
    }
    fclose(itemFile);

    gettimeofday (&tvalAfter, NULL); // End of timer
    double timeAft = tvalAfter.tv_sec+(tvalAfter.tv_usec/1000000.0);
    printf("Program runtime: %.4f seconds\n",timeAft-timeBef);
}

