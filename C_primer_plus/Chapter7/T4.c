#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch;
    int n_change;
    printf("Enter your letter:\n");
    while ((ch=getchar()) != STOP)
    {
        if (ch == '!')
        {
            putchar('!');
            putchar('!');
            n_change++;
        }
        else if(ch == '.')
        {
            putchar('!');
            n_change++;
        }
        else
        {
            putchar(ch);
        }
    }
    printf("The change times:%2d", n_change);

    return 0;
}
