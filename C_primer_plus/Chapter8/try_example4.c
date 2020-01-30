#include <stdio.h>
int get_choice(void);
int get_int(void);
int get_first(void);
void count(void);

int main(void)
{
    char choice;
    while ((choice=get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a': printf("hello, buy more thing, pay less.\n");
                    break;
            case 'b': putchar('\a');
                    break;
            case 'c': count();
                    break;
            case 'q': break;
            default:  printf("The programe error!\n");
        }
    }
    printf("Good bye!");
    return 0;
}
int get_choice(void)
{
    printf("Enter your choice(q to quit):\n");
    printf("a.advice             b.bell\n");
    printf("c.count              q.quit\n");
    char ch;
    ch = get_first();
    while ((ch<'a' || ch>'c') && ch!='q')
        {
            printf("The input is wrong, enter again:");
            ch = get_choice();
        }
    return ch;
}
int get_first(void)
{
    char ch;
    ch=getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}
void count(void)
{
    int start, stop;
    printf("Enter the start number:");
    start = get_int();
    printf("Enter the stop number:");
    stop = get_int();
    for (int i=start; i<=stop; i++)
    {
        printf("%d \n",i);
    }
    while (getchar() != '\n')
        continue;
}
int get_int(void)
{
    int input;
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is a wrong input, try again:");
    }
    return input;
}