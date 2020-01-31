#include <stdio.h>
#define ROWS 4
#define COLS 5
void showarry(const int ar[][COLS], int rows);
void sum_row(int ar[][COLS], int rows);
void sum_col(int ar[][COLS], int rows);
int sum_2d(int ar[][COLS], int rows);

int main(void)
{
    int arry2d[ROWS][COLS] = {{13,12,1,7,5},{14,23,12,3,4},{12,56,7,4,3},{12,45,63,2,3}};
    int sum_toally = 0;
    printf("The origin arry2d is\n");
    showarry(arry2d, ROWS);
    printf("The sum in rows:\n");
    sum_row(arry2d, ROWS );
    printf("The sum in colums:\n");
    sum_col(arry2d, ROWS);
    sum_toally = sum_2d(arry2d, ROWS);
    printf("The toally sum of the arry2d is:%2d", sum_toally);

    return 0;
}
void showarry(const int arry2d[][COLS], int row)
{
    int i, j;
    for (i=0; i<row; i++)
    {
        for (j=0; j<COLS; j++)
            printf("%d ", arry2d[i][j]);
        putchar('\n');
    }
}
void sum_row(int arry2d[][COLS], int row)
{
    int tol;
    int i, j;
    for (i=0; i<row; i++)
    {
        tol = 0;
        for (j=0; j<COLS; j++)
            tol += arry2d[i][j];
        printf("%d  sum is %2d \n", i+1, tol);
    }
}
void sum_col(int arry2d[][COLS], int row)
{
    int tol;
    int i, j;
    for (i=0; i<COLS; i++)
    {
        tol = 0;
        for (j=0; j<row; j++)
            tol += arry2d[j][i];
        printf("%d sum is %2d \n", i+1, tol);
    }
}
int sum_2d(int arry2d[][COLS], int row)
{
    int tol = 0; 
    int i, j;
    for (i=0; i<row; i++)
    {
        for (j=0; j<COLS; j++)
            tol += arry2d[i][j];
    }
    return tol;
}