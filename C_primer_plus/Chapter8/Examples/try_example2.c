#include <stdio.h>
void display(int ch, int a, int b);
int get_int(void);
int main(void)
{
    char ch;
    int row, cloum;
    printf("Enter the character, the row and the cloum(q to quit):");
    while ((ch=getchar()) != '\n')
    {
        if (ch == 'q')
            break;
        printf("now, enter the row:");
        row = get_int();
        printf("and enter the cloum:");
        cloum = get_int();
        display(ch, row, cloum); 
        while (getchar() != '\n')
            continue;
    }
    printf("Good bye!");
    return 0;
}
int get_int(void)
{
    int input, ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is a wrong input, try again:\n");
        while (getchar() != '\n')
            continue;
    }
    return input;
}
void display(int ch, int row, int cloum)
{
    for (int i=1; i<=row; i++)
    {
        for (int j=1; j<=cloum; j++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}
