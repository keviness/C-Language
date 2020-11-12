#include <stdio.h>
#define ROWS 5
#define COLS 4
void show_arry(int rows, int cols, const int (*ar)[cols]);

int main(void)
{
    int i, j;
    int rows = 10;
    int cols = 5;
    int arry_vla[rows][cols];
    int arry2d[ROWS][COLS] = {{12,3,4,5},{12,45,6,6},\
    {1,3,4,5},{12,56,56,7},{23,4,6,77}};
    printf("The normal arry2d is:\n");
    show_arry(ROWS, COLS, arry2d);
    for (i=0; i<rows; i++)
    {
        for (j=0; j<cols; j++)
            arry_vla[i][j] = i+j*i;
    }
    printf("The VLA arry is:\n");
    show_arry(rows, cols, arry_vla);
    
}
void show_arry(int r, int c, const int ar[r][c])
{
    int i, j;
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            printf("%2d ",ar[i][j]);
        putchar('\n');
    }
} 