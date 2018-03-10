// Program to generate 10,000,000 random numbers and write to file
// Initial code from https://stackoverflow.com/questions/37613522/generating-random-numbers-in-c-and-writing-it-to-a-text-file
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int main(int argc, const char *argv[]){
    FILE *f = fopen("items.txt", "w");
    int *numArray;
    numArray=(int *)malloc(sizeof(int)*FILESIZE);
    for (int i = 0; i < FILESIZE; i++){
        numArray[i]=rand()%FILESIZE; // Array of numbers
    }
    fwrite(numArray,sizeof *numArray,FILESIZE,f); // Writes array to file
    fclose(f); 
}