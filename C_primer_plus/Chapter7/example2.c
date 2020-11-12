#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define END '|'

int main(void)
{
    char character, prev_char;
    long n_chars = 0L;
    int n_lines = 0;
    int  n_words =0; 
    int p_lines =0;
    bool inword = false;
    prev_char = '\n';
    printf("Enter the word:\n");
    while((character=getchar()) != END )
    {
        n_chars++;
        if (character == '\n')
        {
            n_lines++;
        }
        if (!isspace(character) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (isspace(character) && inword)
        {
            inword = false;
        }
        prev_char = character;
    }
    if (character != 'n')
        p_lines = 1;

    printf("The number of characters: %3d \n", n_chars);
    printf("The number of words: %3d \n", n_words);
    printf("The number of lines: %3d \n", n_lines);
    printf("The number of losed lines: %3d \n", p_lines);

    return 0;
}