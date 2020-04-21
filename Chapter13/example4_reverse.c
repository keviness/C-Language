/*** reverse the file content ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 20
int main(int argc, char *argv[])
{
    long last;
    int ch;
    FILE *fp;
    if (argc < 2)
    {
        printf("Usage:%s command need two arguments. \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("Usage: Can\'t find the %s file. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    printf("The reverse content of the %s file. \n", argv[1]);
    for (int count=1L; count<=last; count++)
    {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch!='\r' && ch!='\032')
            putchar(ch);
    }
    putchar('\n');
    if (fclose(fp) !=0 )
    {
        printf("Usage: Error in closing %s file. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    return 0;
}