/*** Chapter13: test8 ***/
//report the counts in the files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch;
    int count = 0;
    FILE *pf;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: the %s program need more than 2 arguments, only %d given.\n", argv[0],argc-1);
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        puts("Enter your text:");
        while ((ch = getchar()) != '\n')
        {
            if (ch == argv[1][0])
            {
                count++;
            }
        }
        printf("There are %d %cs in this text.\n", count, argv[1][0]);
    }
    else
    {
        for (int i=2; i<argc; i++)
        {
            count = 0;
            if ((pf = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "The %s file can\'t be opend.\n", argv[i]);
                continue;
            }
            while ((ch = getc(pf)) != EOF)
            {
                if (ch == argv[1][0])
                    count++;
            }
            printf("there are %d %cs in %s file.\n", count, argv[1][0], argv[i]);
        }
    }
    puts("The done~");
    return 0;
}