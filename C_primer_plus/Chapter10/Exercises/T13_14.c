#include <stdio.h>
#define ROWS 3
#define COLS 5
void store( int rows, int cols, int (*ar)[cols]);
void show(int rows, int cols, int (*ar)[cols]);
double average(int rows, int *ar);
double average2d(int rows, int cols, int (*ar)[cols]);
int max(int rows, int cols, int (*ar)[cols]);

int main(void)
{
    int rows, cols;
    int arry[rows][cols];
    store(ROWS, COLS, arry);
    printf("The arry is:\n");
    show(ROWS, COLS, arry);
    printf("**************\n");
    printf("The max value is:%2d \n", max(ROWS, COLS, arry));
    for (int i=0; i<ROWS; i++)
        printf("The %d row average is: %2g \n", i+1, average(ROWS, arry[i]));
    printf("The average is:%2g \n", average2d(ROWS, COLS, arry));

    return 0;
}
void store(int rows, int cols, int (*ar)[cols])
{
    int r, c;
    for (int r=0; r<ROWS; r++)
    {
        printf("Enter the %2d for %2d colums:\n", r+1, COLS);
        for (c=0; c<cols; c++)
        {
            printf("Enter the colum numbers:");
            scanf("%ld", &ar[r][c]);
        }
    }
}
void show(int rows, int cols, int (*ar)[cols])
{
    int r, c;
    int arry[rows][cols];
    for (r=0; r<rows; r++)
    {
        for (c=0; c<cols; c++)
            printf("%2d ", ar[r][c]);
        putchar('\n');
    }
}
double average(int cols, int ar[cols])
{
    int i, sum=0;
    double avg;
    for (i=0; i<cols; i++)
        sum += ar[i];
    if (cols>0)
        avg = sum/cols;
    else
    {
        avg = 0.0;
    }
    return avg;
}
double average2d(int rows, int cols, int (*ar)[cols])
{
    int r, c, total;
    double avg;
    for (r=0; r<rows; r++)
    {
        for (c=0; c<cols; c++)
            total += ar[r][c];
    }
    if (r * c > 0)
        avg = total/(r * c);
    else
    {
        avg = 0.0;
    }
    return avg;
}
int max(int rows, int cols, int (*ar)[cols])
{
    int r, c;
    int max = ar[0][0];
    for (r=0; r<rows; r++)
    {
        for (c=0; c<cols; c++)
        {
            if (max<ar[r][c])
                max = ar[r][c];
        }
    }
    return max;
}