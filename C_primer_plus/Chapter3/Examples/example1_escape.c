//反转义符号的应用
#include <stdio.h>
int main(void)
{
    double salary;

    printf("Enter the desire salary:$________\b\b\b\b\b\b\b\b");
    while(scanf("%lf", &salary) == 1)
    {
        printf("\a\n\tThe %4.2lf a month is %4.2lf a year.", salary, salary*12);
        printf("\rIt is nice!\n");
        printf("Enter the next salary:________\b\b\b\b\b\b\b\b");
    }
    
    return 0;
}