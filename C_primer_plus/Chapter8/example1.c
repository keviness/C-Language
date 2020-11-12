/*a guess number game*/
#include <stdio.h>
int main(void)
{
    int character;
    int ch = 0;
    int value = 10;
    printf("q to quit:");
    while ((character=getchar())!='q')
    {
        printf("Enter you number:");
        scanf("%d", &ch);
        if (ch==value)
        {
            printf("The ture!\n");
            break;
        }
        else
        {
            printf("try again!\n");
        }
        while (getchar()!='\n')
            continue;
    }
    printf("The done!");

    return 0;
}