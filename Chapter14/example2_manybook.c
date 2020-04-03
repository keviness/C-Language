/*** structure array ***/
#include <stdio.h>
#include <string.h>
#define MAXTITLE 80
#define MAXAUTHOR 80
#define MAXSIZE 20
char * s_gets(char *str, int n);
struct manybook
{
    char title[MAXTITLE];
    char author[MAXAUTHOR];
    float value;
};

int main(void)
{
    int count = 0;
    struct manybook library[MAXSIZE];
    puts("Enter The title of the book:");
    while (count<MAXSIZE && s_gets(library[count].title, MAXTITLE) && library[count].title[0]!='\0')
    {
        puts("Enter the author of the book:");
        s_gets(library[count].author, MAXAUTHOR);
        puts("Enter the value of the book:");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXSIZE)
        {
            puts("Enter the next book:");
            puts("Enter the title of the book:");
        }
        count++;
    }
    if (count > 0)
    {
        puts("Here the informations of the book you input:");
        for (int index=0; index<count; index++)
        {
            puts("************");
            printf("The title of the book:%s \n", library[index].title);
            printf("The author of the book:%s \n", library[index].author);
            printf("The value of the book:%s \n", library[index].value);
        }
    }
    else
    {
        printf("The library list in empty!\nThe done~");
    }
    return 0;
}
char * s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}