/*** Chapter13: test12 ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROW 20
#define COLUM 30
#define NAME 20

char *s_gets(char *str, int num);
int main(void)
{
    FILE *pf_source;
    FILE *pf_target;
    int i, j;
    char source_name[NAME];
    char target_name[NAME];
    char source[ROW][COLUM];
    char target[ROW][COLUM+1];
    char *ch = " .':~*= %#";

    puts("Enter the source file name:");
    s_gets(source_name, NAME);

    if ((pf_source = fopen(source_name, "r")) == NULL)
    {
        printf("The file: %s can\'t be opend.\n", source_name);
        exit(EXIT_FAILURE);
    }
    for (i=0; i<ROW; i++)
    {
        for (j=0; j<COLUM; j++)
        {
            if (fscanf(pf_source, "%d", &source[i][j]) == 1)
            {
                target[i][j] = ch[source[i][j]];
            }
        }
        target[i][j] = '\0';
    }


    puts("Enter the target file name:");
    s_gets(target_name, NAME);
    if ((pf_target = fopen(target_name, "w")) == NULL)
    {
        printf("The file: %s can\'t be opend.\n", target_name);
        exit(EXIT_FAILURE);
    }
    puts("The file content:");
    for (i=0; i<ROW; i++)
    {
        fprintf(stdout, "%s\n", target[i]);
        fprintf(pf_target, "%s\n", target[i]);
    }
    if (fclose(pf_source)!=0 || fclose(pf_target)!=0)
    {
        printf("Error in closing these files\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\0' && *str!='\n')
        {
            str++;
        }
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ptr;
}