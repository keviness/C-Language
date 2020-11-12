#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(void)
{
    char ch;
    int n_word;
    int n_char;
    int n_punct;
    bool inword = false;
    while ((ch=getchar()) != EOF)
    {
        n_char++;
        if (ispunct(ch) && !isspace(ch))
            n_punct++;
        if (!isspace(ch) && !inword)
            inword = true;
            n_word++;
        if (isspace(ch) && inword)
            inword = false;
    }
    printf("The number of character is:%2d \n", n_char);
    printf("The number of words is:%2d \n", n_word);
    printf("The number of punctuation is:%2d \n", n_punct);
    printf("The average of word per words is%2d", (n_char-n_punct)/n_word);

    return 0;
}