/*menuette*/
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
    int choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a': printf("Buy low, sell high.\n");
                    break;
            case 'b': putchar('\a');
                    break;
            case 'c': count();
                    break;
            default: printf("programe error!");
        }
    }
    printf("Good Bye!");

    return 0;
}
void count(void)
{
    int n,i;
    printf("count how far:");
    n = get_int();
    for (i=1; i<=n; i++)
        printf("%d\n", i);
    while (getchar() != '\n')
        continue;
}
int get_int(void)
{
    int input;
    char ch;
    while (scanf("%ld", &input)!=1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf("is not a integer.\n pleade enter again:");
    }
    return input;
}
char get_choice(void)
{
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a.advice               b.bell\n");
    printf("c.count                q.quit\n");
    ch = get_first();
    while ((ch<'a' || ch>'c') && ch!='q')
    {
        printf("please response with a, b, c or q: \n");
        ch = get_first();
    }
    return ch;
}
char get_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}