#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
char *get_chars(char *st, int n);

int main(void)
{
    char input[SIZE];
    puts("Enter your letters:");
    while (get_chars(input, SIZE) && input[0]!='\0')
    {
        puts("The letters you input:");
        puts(input);
    }
    puts("The done~");
    
    return 0;
}
char *get_chars(char *st, int num)
{
    int i = 0;
    char ch;
    char *ptr = st;
    while (i<num && *st!='\0' && (ch=getchar())!=EOF)
    {
        if (isspace(ch))
            break;
        else
        {
            st[i] = ch;
            i++;
        }
    }
    if (ch == EOF)
        return NULL;
    else
    {
        st[i] = '\0';
        return ptr;
    }
}