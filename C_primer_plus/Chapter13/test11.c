/*** Chapter13: test11 ***/
//The application of the strstr() function
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256
int main(int argc, char *argv[])
{
    FILE *pf;
    char line[SIZE];
    if (argc < 3)
    {
        printf("The %s program need more than 3 arguments, only %d given.\n", argv[0], argc-1);
        exit(EXIT_FAILURE);
    }
    if ((pf = fopen(argv[1], "r")) == NULL)
    {
        printf("The %s file can\'t be opend.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, SIZE, pf) != NULL)
    {
        if (strstr(line, argv[2]) != NULL)
            fputs(line, stdout);
    }
    if (fclose(pf) != 0)
    {
        printf("The file %s can\'t be closed.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}