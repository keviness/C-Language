/*** Chapter13: test4 ***/
//list the argument values content sequentially
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pf;
    char ch;

    if (argc < 2)
    {
        printf("Usage: The %s program need more than two arguments, only %d given.\n", argv[0], argc-1);
        exit(EXIT_FAILURE);
    }
    for (int i=1; i<argc; i++)
    {
        if ((pf = fopen(argv[i], "r")) == NULL)
        {
            printf("Usage: Can\'t open the file: %s \n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(pf)) != EOF)
        {
            putc(ch, stdout);
        }
        putchar('\n');
        
        if (fclose(pf) != 0)
        {
            printf("The %s file can\'t be closed! \n", argv[i]);
        }
    }

    return 0;
}