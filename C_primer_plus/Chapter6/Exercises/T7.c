#include <stdio.h>
#include <string.h>
int main(void)
{
    char word[20];
    char element;
    int length;
    printf("How many numbers do you want:");
    scanf("%d", &length);
    for (int i=0; i<=length; i++)
    {
        printf("Enter the word:");
        scanf("%c", &element);
        word[i] = element;
    }
    printf("the reverse word of the word you input:");
    for (int j=strlen(word); j>=0; j--)
    {
        printf("%c", word[j]);
    }

    return 0;
}