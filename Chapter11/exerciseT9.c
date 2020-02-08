/*---reverse the string---*/
#include <stdio.h>
#include <string.h>
#define SIZE 20
void reverse(char *str);
int main(void)
{
    char input[SIZE] = "wonderful";
    puts("The origin string:");
    puts(input);
    reverse(input);
    puts("The reverse string:");
    puts(input);
    return 0; 
}
void reverse(char *str)
{
    char *ptr = str+(strlen(str)-1);
    char temp;
    while (*str && *ptr!=*str)  // if its enqual, loop stop
    {
        temp = *str;
        *str = *ptr;
        *ptr = temp;
        str++;
        ptr--;
    }
}