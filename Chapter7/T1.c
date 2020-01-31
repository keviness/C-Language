#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define END '#'

int main(void)
{
    char character, pre_char;
    int n_chars = 0;
    int n_lines = 0;
    int n_lose = 0;
    int n_space = 0;
    bool inword = false;
    printf("Enter the letter:\n");
    pre_char = '\n';
    while ((character=getchar()) != END)
    {
        n_chars ++;
        if (character == '\n')
            n_lines++;
        if (isspace(character) && inword)
        {
            n_space++;
            inword = false;
        }
        if (!isspace(character) && !inword)
        {
            inword = true;
        }
        pre_char = character;
    }
    if (pre_char != '\n')
        n_lose = 1;
    printf("The number of character:%3d \n", n_chars);
    printf("The number of lines:%3d \n", n_lines);
    printf("The number of space:%3d \n", n_space);
    printf("The number of lose lines:%3d", n_lose);

    return 0;
}