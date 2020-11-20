/*show characters*/
#include <stdio.h>
void display(char cr, int rows, int lines);
int main(void)
{
    int rows, lines;
    char character;
    printf("Enter the character,rows and lines(Enter to quit):");
    while ((character=getchar()) != '\n')
    {
        if(scanf("%d %d", &rows, &lines) != 2)
        {   printf("The wrong,try again!\n");
            break;
        }
        display(character, rows, lines);
        while (getchar() != '\n')
            continue;
    }
    printf("Good BYe!");

    return 0;
}
void display(char cr, int rows, int lines)
{
    for (int i=1; i<=rows; i++)
    {
        for (int y=1; y<=lines; y++)
        {
            putchar(cr);
        }
        putchar('\n');
    } 
}
