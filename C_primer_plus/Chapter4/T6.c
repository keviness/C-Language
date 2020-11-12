#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[10], last_name[10];

    printf("Enter your name:");
    scanf("%s %s", first_name, last_name);
    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n", strlen(first_name), strlen(first_name)\
    , strlen(last_name), strlen(last_name));
    printf("%s %s\n", first_name, last_name);
    printf("%-*d %-*d", strlen(first_name),strlen(first_name),\
    strlen(last_name),strlen(last_name));

    return 0;
}