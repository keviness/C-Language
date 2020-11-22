/*A example for compound literal*/
#include <stdio.h>
#define ROWS 5
#define COLS 4
void show_arry(int r, const int *ar);
void show_arry2d(int r, int c, const int (*ar)[c]);
int sum_arry(int r, const int *ar);
int sum_arry2d(int r, int c, const int (*ar)[c]);

int main(void)
{
    int i,j;
    int rows = 10;
    int cols = 8;
    int arry[ROWS]={12,45,67,56,56};
    int arry2d[ROWS][COLS] = {{12,34,56,34},{1,3,4,5},\
    {12,45,32,57},{23,57,34,32},{12,56,34,23}};
    int arry2d_vla[rows][cols];
    for (i=0; i<rows; i++)
    {
        for (j=0; j<cols; j++)
            arry2d_vla[i][j] = i+i*j;
    }
    printf("The normal arry :\n");
    show_arry(ROWS, arry);
    printf("The VLA arry:\n");
    show_arry2d(rows, cols, arry2d_vla);
    printf("The 2darry:\n");
    show_arry2d(ROWS, COLS, arry2d);

    printf("************ \n");
    printf("The sum of normal arry:%2d\n", sum_arry(ROWS, arry));
    printf("The sum of arry2d:%2d\n", sum_arry2d(ROWS, COLS, arry2d));
    printf("The sum of arry2d_vla:%2d \n", sum_arry2d(rows, cols, arry2d_vla));
    return 0;
}
void show_arry(int r, const int *ar)
{
    int i;
    for (i=0; i<r; i++)
        printf("%2d ", ar[i]);
    putchar('\n');
}
void show_arry2d(int r, int c, const int (*ar)[c])
{
    int i, j;
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            printf("%2d ", ar[i][j]);
        putchar('\n');
    }
}
int sum_arry(int r, const int *ar)
{
    int i, tol;
    for (i=0; i<r; i++)
        tol += ar[i];
    return tol;
}
int sum_arry2d(int r, int c, const int (*ar)[c])
{
    int i, j, tol;
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            tol += ar[i][j];
    }
    return tol;
}