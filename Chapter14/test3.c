/*** library sort ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 20
#define TITLE 25
#define AUTHOR 25
char *s_gets(char *str, int n);
struct book {
    char title[TITLE];
    char author[AUTHOR];
    float value;
};
void handleline(void);
void sort_title(struct book *pst[MAXLINE], int n);
void sort_value(struct book *pst[MAXLINE], int n);
void showinfo(struct book *pst[], int n);
int main(void)
{
    int count = 0;
    struct book *pst[MAXLINE];
    struct book libray[MAXLINE];
    puts("Enter the title of the book:");
    while (count<MAXLINE && s_gets(libray[count].title, TITLE) && libray[count].title[0]!='\0')
    {
        puts("Enter the author of the book:");
        s_gets(libray[count].author, AUTHOR);
        puts("Enter the value of the book:");
        scanf("%f", &libray[count].value);
        pst[count] = &libray[count];
        count++;
        handleline();
        if (count < MAXLINE)
        {
            puts("Enter the nxet title of book:");
        }
    }
    puts("The result after sorted by title:");
    sort_title(pst, count);
    showinfo(pst, count);
    puts("**************");
    puts("The result after sorted by value:");
    sort_value(pst, count);
    showinfo(pst, count);

    return 0;
}

void sort_title(struct book *pst[], int num)
{
    int top, search;
    struct book *temp;
    for (top=0; top<num-1; top++)
    {
        for (search=1; search<num; search++)
        {
            if (strcmp(pst[top]->title, pst[search]->title) > 0)
            {
                temp = pst[top];
                pst[top] = pst[search];
                pst[search] = temp;
            }
        }
    }
}

void sort_value(struct book *pst[], int num)
{
    struct book *temp;
    int search, top;
    for (top=0; top<num-1; top++)
    {
        for (search=1; search<num; search++)
        {
            if (pst[top]->value > pst[search]->value)
            {
                temp = pst[top];
                pst[top] = pst[search];
                pst[search] = temp;

            }
        }
    }
}

void showinfo(struct book *pst[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("The %s book by %s author, value:%f \n",\
         pst[i]->title,pst[i]->author,pst[i]->value);
    }
}

void handleline(void)
{
    while (getchar() != '\n')
    {
        continue;
    } 
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