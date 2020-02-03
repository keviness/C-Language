#include <stdio.h>
#include <string.h>
#define SIZE 10
char *s_gets(char *str, int n);
int main(void)
{
    char * option[SIZE] = {"astroment", "astronomy", "astr", "asert"};
    int i = 0;
    int count = 0;
    for (i=0; i<SIZE; i++)
    {
        if (strncmp(option[i], "astro", 5) == 0)
        {
            printf("The %d option is the ringht option: %s \n", i+1, option[i]);
            count++;
        }   
    }
    printf("Find %d options is right!\n");
    printf("The done!");
    return 0;
}