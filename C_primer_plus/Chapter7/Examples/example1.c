#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SPACE '|'

int main(void)
{
    char character, prev_char;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    bool inword = false;

    printf("Enter the word:\n");
    prev_char = '\n';
    while ((character = getchar()) != SPACE)
    {
        n_chars++;
        if (!isspace(character) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (character == '\n')
        {
            n_lines++;
        }
        if (isspace(character) && inword)
        {
            inword = false;
        }
        prev_char = character;
    }
    if (prev_char != '\n')
        p_lines = 1;
    
    printf("The characters: %3d \n", character);
    printf("The words: %3d \n", n_words);
    printf("the entirely lines: %3d \n", n_lines);
    printf("the lose lines: %3d \n", p_lines);

    return 0;

}
