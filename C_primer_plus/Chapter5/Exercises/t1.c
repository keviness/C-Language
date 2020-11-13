#include <stdio.h>
#define SIZE 60.0
int main(void)
{
    int number;
    
    printf("Enter the number(minuters):");
    scanf("%d", &number);
    while(number >0)
    {
        printf("Convert Hours:%3f\n", number/SIZE);
        printf("Convert Seconds:%3d \n", number* SIZE);
        scanf("%d", &number);
    }
    printf("the end!");

    return 0;
}