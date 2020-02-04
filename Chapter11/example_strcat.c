/*--strcat example--*/
#include <stdio.h>
#include <string.h>
#define SIZE 10
char * s_gets(char *str, int n);
int main(void)
{
    char flowers[SIZE];
    char bugs[SIZE];
    char add[]= " smells wonderful!";
    puts("Enter your flower\'s name:");
    if (s_gets(flowers, SIZE))
    {
        puts(flowers);
        strcat(flowers, add);
        puts(flowers);
    }
    puts("Enter your favourite bug:");
    if (s_gets(bugs, SIZE))
    {
        puts(bugs);
        strncat(bugs, add, SIZE-strlen(bugs));
        puts(bugs);
    }
    return 0;
}
char * s_gets(char *str, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(str, n, stdin);
    if (ret_val != NULL)
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
    return ret_val;
}