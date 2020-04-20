/*** add a word ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 40

int main(int argc, char *argv[])
{
    char word[LEN];
    int count;
    FILE *fp;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename two arguments \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Usage: Can\'t open the %s file. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    puts("Enter the informations:");
    while ((fscanf(stdin, "%s", word))==1 && word[0]!='#')
    {
        fprintf(fp, "%s ", word);
        count++;
    }
    puts("*********\nThe content of the file:");
    rewind(fp);
    while ((fscanf(fp, "%s", word))==1 && count>0)
    {
        fprintf(stdout, "the %d word: %s \n",count, word);
        count--;
    }
    if (fclose(fp) != 0)
    {
        printf("Usage: The %s file can\'t close. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    return 0;
}