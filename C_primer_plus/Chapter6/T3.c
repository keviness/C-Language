#include <stdio.h>

int main(void)
{
    int rows;
    char word, w;
    printf("enter the rows and the first word(5 p):");
    scanf("%d %c", &rows, &word);

    for (int i=1; i<=rows; i++)
    {
        for (int j=1, w=word; j<=i; j++, w++)
        {
            printf("%c", w);
        }
        printf("\n");
    }

    return 0;
}
