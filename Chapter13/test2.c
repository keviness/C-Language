/*** Chapter13: test2 ***/
//fill the file content by copying the other file
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define SIZE 256
int main(int argc, char *argv[])
{
    FILE *pf_target;
    FILE *pf_source;
    //char ch;
    char target;
    int count;
    char temp[SIZE];
    char read[SIZE];
    if (argc < 3)
    {
        printf("The program %s need 2 arguments, only %d given \n", argv[0], argc-1);
        exit(EXIT_FAILURE);
    }
    if ((pf_source = fopen(argv[1], "rb")) == NULL)
    {
        printf("Usage: The %s file can\'t be opened. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((pf_target = fopen(argv[2], "wb")) == NULL)
    {
        printf("Usage: The %s file can\'t be opened. \n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((count = fread(temp, sizeof(char), SIZE, pf_source)) > 0)
    {
        fwrite(temp, sizeof(char), count, pf_target);
    }
    printf("There are %d charactes from %s file write in %s file. \n", count, argv[1], argv[2]);
    /*
    while ((ch = getc(pf_source)) != EOF)
    {
        putc(ch, pf_target);
        count++;
    }
    printf("There are %d characters from %s file had been write in the %s file \n", count, argv[1], argv[2]);
    rewind(pf_target);
    puts("The file content:");
    while ((target = getc(pf_target)) != EOF)
    {
        putchar(target);
    }
    puts("\nThat is all");
    */
   rewind(pf_target);
    puts("The file content:");
    while (fread(read, sizeof(char), SIZE, pf_target))
    {
        printf("%s", read);;
    }
    
    if ((fclose(pf_source))!=0 || fclose(pf_target)!=0)
    {
        printf("Error in closing file. \n");
    }

    return 0;
}