// Program to generate 10,000,000 random numbers and write to file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *f = fopen("items.txt", "w");
    for (int i = 0; i < 10000000; ++i)
    {
        fprintf(f, "%d", rand() % 10000000);
        fprintf(f, "\n"); /* Probably nice to make it a line. */
    }
    
}