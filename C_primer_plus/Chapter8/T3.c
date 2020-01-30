#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int n_word;
    int n_upper;
    int n_lower;
    printf("Enter your letters:");
    while ((ch=getchar()) != EOF)
    {
        if (!isspace(ch))
            n_word ++;
        if (!isspace(ch) && isupper(ch))
            n_upper++;
        if (!isspace(ch) && islower(ch))
            n_lower++;
    }
    printf("The number of character is:%2d \n", n_word);
    printf("The number of upperr is:%2d \n", n_upper);
    printf("The number of lower is:%2d", n_lower);

    return 0;
}