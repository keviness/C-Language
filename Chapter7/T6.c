#include <stdio.h>
#define STOP '#'
int main(void)
{
    char ch, pre_ch;
    int n = 0;
    printf("Enter your letters:\n");
    pre_ch = 'e';
    while ((ch=getchar()) != STOP)
    {
        if (pre_ch=='e' && ch=='i')
            n++;
        pre_ch = ch;
    }
    printf("The number of \'ei\' is:%d", n);
    return 0;
}