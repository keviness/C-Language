#include <stdio.h>
int main(void)
{
    int headline, downline;
    int sum=0;
    while (headline < downline)
    {
        printf("Enter the headline and downline(4 7):");
        scanf("%d %d", &headline, &downline);
        for (int i=headline; i<=downline; i++)
        {
            sum += i*i;
        }
        printf("the sum of the numbers:%d \n", sum );
    }
    printf("The wrong!");

    return 0;
}
