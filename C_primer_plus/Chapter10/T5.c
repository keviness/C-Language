#include <stdio.h>
#define SIZE 5
void sort(int *ar,int r);
void reverse(int *ar, int r);
void show(int *ar, int r);
int main(void)
{
    int ar[SIZE] = {1,4,5,2,4};
    printf("The origin arry:\n");
    show(ar, SIZE);
    printf("The sorted arry:\n");
    sort(ar, SIZE);
    show(ar, SIZE);
    printf("The reverse arry:\n");
    reverse(ar, SIZE);
    show(ar, SIZE);

    return 0;
}
void show(int *ar, int r)
{
    int i;
    for (i=0; i<r; i++)
        printf("%2d ", ar[i]);
    putchar('\n');
}
void sort(int *ar, int r)
{
    int i, temp;
    int max = ar[0];
    for (i=0; i<r; i++)
    {
        if (max<ar[i])
        {
            max = ar[i];
            ar[i] = temp;
            temp = max;
        }
    } 
}
void reverse(int *ar, int r)
{
    int i;
    for (i=0; i<3; i++)
        ar[i] = ar[r-i];
}