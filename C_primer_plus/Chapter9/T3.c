#include <stdio.h>
#define STOP '#'
void print_char(char ch, int rows, int lines);
int main(void)
{
    char ch;
    int rows, lines;
    printf("Enter the character,rows,lines(# to quit):");
    while ((ch=getchar()) != STOP)
    {
        if (ch == '\n')
            continue;
        if (scanf("%d %d", &rows, &lines) != 2)
        {
            printf("The wrong input!try again:");
            continue;
        }
        print_char(ch, rows, lines);
        printf("Enter the character,rows,lines(#to quit):");
    }
    printf("Good bye!");

    return 0;
}
void print_char(char ch, int rows, int lines)
{
    for (int i=1; i<=rows; i++)
    {
        for (int j=1; j<=lines; j++)
            putchar(ch);
        putchar('\n');
    }
}