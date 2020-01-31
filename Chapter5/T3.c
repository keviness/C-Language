#include <stdio.h>

int main(void)
{
    int days;
    printf("Enter your days:");
    scanf("%d", &days);
    while(days > 0)
    {
        printf("%d weeks, and %d days\n", days/7, days%7);
        printf("Enter your days(0 to quit):");
        scanf("%d", &days);
    }
    printf("The end!");

    return 0;
}