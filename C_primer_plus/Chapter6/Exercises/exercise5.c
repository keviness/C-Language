/*** chapter6: exercise5 ***/
#include <stdio.h>

int main(void)
{
    const int rows = 5;
    char c = 'A';
    int count = 0;
    int blanks = rows-1;
    int i, j, m;
    for (i=0; i<rows; i++)
    {
        for (j=rows; rows-j>=0; j--)
        {
            printf("%*s%c", j, "", c++);
            count++;
        }
        m = count-rows;
        while(m > 0)
        {
            printf("%c", c--);
            m--;
        }
        putchar('\n');
    }

    return 0;
}