/*---exercise T3 T4---*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10
char *get_chars(char *st, int num);

int main(void)
{
    char input[SIZE];
    puts("Enter your letter:");
    while (get_chars(input, SIZE) != NULL)
    {
        puts("The letter you input:");
        puts(input);
    }
    puts("The done~");

    return 0;
}
char *get_chars(char *st, int num)
{
    int i = 1;
    char ch;
    char *ptr;
    ptr = st;
    /*skip the white space*/
    while ((ch=getchar())!=EOF && isspace(ch))
        continue;
    if (ch == EOF)
        return NULL;
    else      //if it is\'s not EOF,it is a character 
    {
        *st = ch;   //get the character
        st++;  //pointer the next place
    }
    /*----catch the characters------*/
    while ((ch=getchar())!=EOF && !isspace(ch) && i<num)
    {
        *st = ch;
        st++;
        i++;
    }
    *st = '\0';    //add the \0
    if (ch == EOF)
        return NULL;
    else    //if it is a space (\n or orther space(\t \b \r))
    {
        while (ch != '\n')
            ch = getchar(); //get the space except \n
        return ptr;
    } 
}