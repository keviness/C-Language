/*** structure type ***/
#include <stdio.h>
#include <string.h>
#define MAXTITLE 80
#define MAXAUTHOR 80
char * s_gets(char *str, int n);
struct book
{
    char title[MAXTITLE];
    char author[MAXAUTHOR];
    float value;
};

int main(void)
{
    struct book library;

    puts("Enter your book names:");
    s_gets(library.title, MAXTITLE);
    puts("Enter the author:");
    s_gets(library.author, MAXAUTHOR);
    puts("Enter the value of the book:");
    scanf("%lf", &library.value);

    puts("The informations of the book:");
    printf("The title of the book:%s \n", library.title);
    printf("The author of the book:%s \n", library.author);
    printf("The value of the book:%2.3f \n", library.value);
    printf("the title:%s the author:%s the value:%g \n", library.title, library.author, library.value);
    puts("The done~");
    return 0;
}

char * s_gets(char *st, int num)
{
    char * ptr;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        while (*st!='\n' && *st!='\0')
        {
            st++;
        }
        if (*st == '\n')
            *st = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}