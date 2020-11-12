#include <stdio.h>
int main(void)
{
    char name[10];
    int age;
    printf("\aHello, what\'s your name:-----\b\b\b\b\b");
    scanf("%s", name);
    printf("\aAnd how old are you:----\b\b\b\b");
    scanf("%d", &age);
    printf("\aHi %s, \nwelcome, you are %d years old this year!", name, age);

    return 0;
}