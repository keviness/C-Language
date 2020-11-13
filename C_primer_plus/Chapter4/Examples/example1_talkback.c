//4.1 talkback
#include <stdio.h>
#include <string.h>
#define SIZE 10
int main(void)
{
    int weight;
    char name[SIZE];

    printf("Enter your name:");
    while (scanf("%s", name) == 1 && name[0]!='q')
    {
        printf("Enter your weight:");
        scanf("%lf", &weight);
        printf("You name length: %d \n", strlen(name));
        printf("The name size: %zd \n", sizeof(name));
        printf("The name has %d chars \n", sizeof(name)/sizeof(name[0]));

        printf("Enter the next name:");
    }
    printf("The done~");

    return 0;
}