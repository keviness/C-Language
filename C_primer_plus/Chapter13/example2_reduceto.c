/*** reduce to ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 40
int main(int argc, char *argv[])
{
    FILE *in, *out;
    char name[LINE];
    int count = 0;
    int ch;
    if (argc < 2)
    {
        printf("Usage: Can\'t open the %s file. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Usage: can\'t find the %s file. \n", argv[1]);
    }
    strcpy(name, argv[1]);
    name[LINE-5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Usage: Can\'t crate the %s file \n", name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(in)) != EOF)
    {
        putc(ch, out);
        putchar(ch);
        count++;
    }
    if (fclose(in)!=0 || fclose(out)!=0)
    {
        fprintf(stderr, "Usage: Error in closing files. \n");
    }

    return 0;
}
