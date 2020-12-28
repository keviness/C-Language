#include <stdio.h>
#define MAX 10

int main(void)
{
    int i;
    int arr[MAX];
    int count = 0;
    char nums[MAX];

    do
    {
        printf("Enter the %d number: ", count+1);
        scanf("%d", &arr[count++]);
        while (getchar() != '\n') continue;
        printf("Are you continue?(Y/N):");
        scanf("%s", nums);
        while (getchar() != '\n') continue;
    }while ((nums[0]!='N'||nums[0]!='n') && count<MAX);

    printf("The array: \n");
    for (i = 0; i<count; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
