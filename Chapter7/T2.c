#include <stdio.h>
#include <ctype.h>
#define STOP '#'
int main(void)
{
    char character;
    int n_char;
    printf("Enter your letters: \n");
    while ((character=getchar()) != STOP)
    {
        n_char++;
        printf("%c ", character);
        printf("%d ", character);
        if (n_char%8 == 0)
        {    
            putchar('\n');
        }
    }
    return 0;
}
