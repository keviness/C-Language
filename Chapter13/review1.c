/*** review 13-4 ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fptr;
    int file_count;
    int bytes;
    if (argc < 1)
    {
        fprintf(stderr,"Usage:The %s file more than two arguments. \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (file_count=1; file_count<argc; file_count++)
    {
        if ((fptr=fopen(argv[file_count], "a+")) == NULL)
        {
            fprintf(stderr,"Usage:The %s file can\'t be opend.", argv[file_count]);
            exit(EXIT_FAILURE);
        }
        while ((bytes=getc(fptr)) != EOF)
            putc(bytes, stdout);
        if (fclose(fptr) != 0)
        {
            fprintf(stderr, "Usage:The %s file.", argv[file_count]);
        }
    }

    return 0;
}