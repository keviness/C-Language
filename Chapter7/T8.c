#include <stdio.h>
#define STOP 'q'
#define FIRST 8.75
#define SECOND 9.33
#define THIRD 10.00
#define FOUTH 11.20
int get_choice(void);
int get_first(void);
int get_hour(void);
double count(double n, int h); 
int main(void)
{
    int ch;
    double pay;
    while ((ch=get_choice()) != STOP)
    {
        switch (ch)
        {
            case 'a': pay = count(FIRST, get_hour());
                    break;
            case 'b': pay = count(SECOND, get_hour());
                    break;
            case 'c': pay = count(THIRD, get_hour());
                    break;
            case 'd': pay = count(FOUTH, get_hour());
                    break;
            case 'q': break;
            default: printf("The program error!\n");
                    break;
        }
        printf("The pay is:%g \n", pay);
    }
    printf("Good bye!\n");

    return 0;
}
int get_choice(void)
{
    int ch;
    for (int i=0; i<=20; i++)
        printf("*");
    printf("\nEnter the choice:\n");
    printf("a.$8.75            b.$9.33 \n");
    printf("c.$10.00           d.$11.20 \n");
    printf("q.quit \n");
    for (int j=0; j<=20; j++)
        printf("*");
    putchar('\n');
    ch = get_first();
    while ((ch<'a' || ch>'d') && ch != 'q')
    {
        printf("The error input!try again:\n");
        ch = get_first();
    }
    return ch;
}
int get_first(void)
{
    int input;
    input = getchar();
    while (getchar() != '\n')
        continue;
    return input;
}
int get_hour(void)
{
    int input;
    printf("Enter your work hours(a int):");
    while (scanf("%d", &input) != 1)
    {
        while ((input=getchar()) != '\n')
        {
            putchar(input);
            printf(" is a wrong input, try again:");
        }
    }
    while (getchar() != '\n')
        continue;
    return input;
}
double count(double m, int hour)
{
    double answer;
    answer = m * hour;
    return answer;
}