/*** Chapter7: list7-6 ***/
/*** Chapter7: list7-3;list7-4 ***/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSTAGE 10
#define swap(type, x, y) do{type t = x; x=y; y=t;} while (0)

int main(void)
{
    int i, j, stage;
    int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a[8];
    double mins;
    clock_t start, end;
    srand(time(NULL));

    printf("Enter the number that lost: \n");
    start = clock();

    for (stage=0; stage<MAXSTAGE; stage++)
    {
        int x = rand()%9;
        int ans;
        for (i=j=0; i<9; i++)
        {
            if (i != x)
            {
                a[j++] = dgt[i];
            }
        }

        for (i=7; i>0; i--)
        {
            int j = rand()%(i+1);
            if (i != j)
                swap(int, a[i], a[j]);
        }

        for (i=0; i<8; i++)
        {
            printf("%d ", a[i]);
        }
        printf(":");
        do
        {
            scanf("%d", &ans);
        } while (ans != dgt[x]);        
    }
    end = clock();

    mins = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Using time: %2.4lf", mins);

    if (mins > 25.0)
        printf("Too delay \n");
    else if (mins > 20.0)
        printf("Delay \n");
    else if (mins > 15.0)
        printf("good \n");
    else
        printf("really good \n");
    
    return 0;
}