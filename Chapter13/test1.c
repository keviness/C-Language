/*** Chapter13 test1 ***/
/*author: keviness
*date: 2020.6.17
*/
//read the file by input file name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 20
char * s_gets(char *str, int num);

int main(void)
{
    char file_name[NAME];
    FILE *pf;
    char ch;
    int count;

    puts("Enter the file name please:");
    while (s_gets(file_name, NAME)==NULL && file_name[0]=='\0')
    {
        printf("The file: %s can\'t exit! try again:\n", file_name);
    }
    if ((pf = fopen(file_name, "r+")) == NULL)
    {
        printf("Can\'t open the file: %s. \n", file_name);
        exit(EXIT_FAILURE);
    }
    puts("The information of this file:");
    while ((ch = getc(pf)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    printf("\nThere are %d characters in this file. \n", count);
    if (fclose(pf) != 0)
    {
        printf("Error in closing the %s file. \n", file_name);
    }

    return 0;
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
        {
            str++;
        }
        if (*str = '\n')
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