#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i, j;
    puts("You argument value:");
    for (i=0; i<argc-1; i++)
        printf("The %d is: %s \n", i+1, argv[i+1]);
    puts("The reverse argument values:");
    for (j=argc-1; j>0; j--)
        printf("%s ", argv[j]);

    return 0;
}