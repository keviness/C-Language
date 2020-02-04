#include <stdio.h>
#include <string.h>
#define LIM 5
#define SIZE 20
void sort_str(char * st[], int n);
char *s_gets(char *str, int m);
int main(void)
{
    char input[LIM][SIZE];
    char *pstr[LIM];
    int ct = 0;
    puts("Enter your leters");
    while (ct<LIM && s_gets(input[ct], LIM)!=NULL && input[ct][0]!='\0')
    {
        pstr[ct] = input[ct];
        ct++;
    }
    sort_str(pstr, LIM);
    puts("The content after calling sorted:");
    for (int i=0; i<ct; i++)
    {
        puts(pstr[i]);
    }
    return 0;
}
void sort_str(char *st[], int n)
{
    int top, seek;
    char *temp;
    for (top=0; top<n-1; top++)
    {
        for (seek=top+1; seek<n; seek++)
        {
            if (strcmp(st[top], st[seek]) > 0)
            {
                temp = st[top];
                st[top] = st[seek];
                st[seek] = temp;
            }
       }
    }
}
char *s_gets(char *str, int m)
{
    char *ptr;
    int i = 0;
    ptr = fgets(str, m, stdin);
    if (ptr != NULL)
    {
        while (str[i]!='\n' && str[i]!='\0')
            i++;
        if (str[i] == '\n')
            str[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}