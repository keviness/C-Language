/**list5-9 Clarify C language*/
#include <stdio.h>
#include <string.h>
#define MAX 10
#define EATLINE while(getchar()!='\n') continue

int main (void)
{
    int i = 0;
    int array[MAX];
    int count = 0;
    int retry;

    do
    {
        printf("Enter the %d number:", count+1);
        scanf("%d", &array[count++ % MAX]);
        EATLINE;

        printf("Do you continue(0/no, 1/yes):");
    }while (scanf("%d", &retry)==1 && retry!=0);

    i = count - MAX;
    if (i < 0) i = 0;
    
    for (; i<count; i++)
    {
        printf("The %d number is %d \n", i+1, array[i%MAX]);
    }
    
    return 0;
}