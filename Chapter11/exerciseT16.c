#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    int ok = 1;
    int ch;
    char mode = 'p';
    if (argc > 2)
    {
        printf("Usage: %s [-p|-u|-l] \n", argv[0]);
        ok = 0;
    }
    else if (argc == 2)
    {
        if (argv[1][0] != '-')
        {
            printf("Usage: %s [-p|-u|-l] \n", argv[0]);
            ok = 0; 
        }
        else
        {
            ok = 1;
            switch (argv[1][1])
            {
            case 'p':
            case 'u':
            case 'l': mode = argv[1][1];
                break;
            default: printf("Usage: %s [-p|-u|-l] %s is a valid input\n", argv[0], argv[1]);
                  printf("The -p is the default input\n");
            }
        }
        
    }
    else
    {
        printf("Usage: %s need a argument[-p|-u|-l] \n");
        ok = 0;
    }
    if (ok)
    {
        while ((ch=getchar()) != '\n')
        {
            switch (mode)
            {
                case 'p': putchar(ch);
                        break;
                case 'u': putchar(toupper(ch));
                        break;
                case 'l': putchar(tolower(ch));
                        break;
            }
        }
    }
    return 0;
}