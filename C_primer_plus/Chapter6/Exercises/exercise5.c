/*** chapter6: exercise5 ***/
#include <stdio.h>

int main(void)
{
    const int rows = 7;
    char c = 'A';
    int count = 0;
    int i, j, m;

    for (i=0; i<rows; i++)
    {
        c = 'A';
        printf("%*s", rows-i-1, "");
        for (j=i; j>=0; j--)
        {
            printf("%c", c++);
        }
        c--;
        for (m=i; m>0; m--)
        {
            printf("%c", --c);
        }
        putchar('\n');
    }

    return 0;
}