#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
char *s_gets(char *str, int n);
void to_upper(char *str);
int count_puct(const char *str);
int main(void)
{
    char input[SIZE];
    int ct = 0;
    puts("Enter your letter:");
    while (s_gets(input, SIZE) && input[0]!='\0')
    {
        puts("The words:");
        puts(input);
        to_upper(input);
        puts("The words after calling toUpper:");
        puts(input);
        printf("The letter with %2d punctions \n", count_puct(input));
        puts("Enter the next letter:");
    }
    puts("Good Bye~");
    return 0;
}
char *s_gets(char *str, int num)
{
    char *ptr;
    int i = 0;
    ptr = fgets(str, num, stdin);
    if(ptr)
    {
        while (str[i]!='\n' && str[i]!='\0')
            i++;
        if (str[i] == '\n')
            str[i] ='\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}
void to_upper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
int count_puct(const char *str)
{
    int count = 0;
    while (*str)
    {
        if (ispunct(*str))
            count++;
        str++;
    }
    return count;
}