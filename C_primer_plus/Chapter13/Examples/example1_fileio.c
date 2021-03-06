/*** standard I/O ***/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long int count;
    int ch;
    FILE *in;
    if (argc < 2)
    {
        printf("Usage:%s filename \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        printf("The %s file can not open! \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    puts("*********\n the information:");
    while ((ch = getc(in)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(in);
    printf("The %s file has %lu characters \n", argv[1], count);

    return 0;
}
