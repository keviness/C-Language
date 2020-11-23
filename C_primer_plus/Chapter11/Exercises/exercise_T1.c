/*--struct fegts() with getchar()--*/
#include <stdio.h>
#include <string.h>
#define SIZE 20
char *get_chars(char *st, int n);
void put_chars(char *st);
int main(void)
{
    char input[SIZE];
    put_chars("Enter your letter:");
    if (get_chars(input, SIZE))
    {
        put_chars(input);
    }
    else
    {
        put_chars("The input is null");
    }
    
}
char *get_chars(char *st, int num)
{
    char ch;
    int i = 0;
    while (i<num && (ch=getchar()) != EOF)
    {
        *st = ch;
        st++;
        i++;
    }
    if (ch == EOF)
        return NULL;
    else
    {
        *st = '\0';
        return st;
    } 
}
void put_chars(char *st)
{
    while (*st!='\0' && st != NULL)
    {
        putchar(*st);
        st++;
    }
    if (st == NULL)
        printf("The wrong!");
    putchar('\n');
}