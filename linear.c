//https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm for fread
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//https://codereview.stackexchange.com/questions/73553/finding-the-size-of-a-file to get file size
// long fsize(FILE *fp) {
//     fseek(fp, 0, SEEK_END);
//     long bytes = ftell(fp);
//     rewind(fp);
//     return bytes;
// }

int main(int argc, const char * argv[]) {
    
    FILE *itemFile;
    itemFile = fopen("items.txt","r");
    bool found = false;
    int inputNum;
    printf("Enter the number to find\n");
    scanf("%d",&inputNum);
    // int size = sizeof(int);
    // long nmemb = fsize(&itemFile);
    // printf("%d",nmemb);
    for(int i=0; i<10000000;i++){
        int number;
        
        fscanf(itemFile, "%d", &number); // Read in integer
        if(number==inputNum){
            printf("Found %d in file\n",inputNum);
            found=true;
        }
        //fread(buffer, size,nmemb, itemFile);
	}
    if(!found){
        printf("Number not found\n");
    }
    fclose(itemFile);
}

