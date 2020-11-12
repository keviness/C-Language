#include <stdio.h>
void hello(void);
int main(void)
{
    char name;
    printf("Hello, what\'s your name:\n");
    hello();
    return 0;
}
void hello(void)
{
    printf("Hello!");
}