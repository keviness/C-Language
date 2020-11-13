//chapter4 exercise2
#include <stdio.h>
#include <string.h>
#define SIZE 20
int main(void)
{
    char name[SIZE];

    printf("Enter the name:");
    while (scanf("%s", name) == 1 && name[0]!='q')
    {
        printf("\"%s\" \n", name);
        printf("\"%20s\" \n", name);
        printf("\"%-20s\" \n", name);
        printf("%*s \n", strlen(name)+3, name);

        printf("Enter the next name:");
    }
    
    return 0;
}