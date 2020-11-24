/*** Chapter14: test10 ***/
//function pointer array
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define EATLINE while(getchar()!='\n')continue
#define INPUTSTR 40
#define POINTER 4

void get_input(char *str);
void to_lower(char *str);
void to_upper(char *str);
void transform(char *str);
int get_choice(void);
char * s_gets(char *str, int num);

int main(void)
{
    char input[INPUTSTR];
    void (*pointer_funct)(char *str);
    int choice;
    //int index;
    get_input(input);
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a':
            case 'A': pointer_funct = to_lower; 
                break;
            case 'b':
            case 'B': pointer_funct = to_upper;
                break;
            case 'c':
            case 'C': pointer_funct = transform;
                break;
            default: printf("The choice you select is wrong! \n");
                break;
        }

        (*pointer_funct)(input);
        puts("The result:");
        puts(input);
    }
    puts("The done~");
    return 0;
}

int get_choice(void)
{
    int choice;

    puts("Enter the choice(a,b,c,q):");
    puts("a) To lower          b) To upper");
    puts("c) Transform         q) Quit");

    while (((choice = getchar())<'a' || choice>'c') && choice!='q')
    {
        EATLINE;
        printf("The choice %c is error, try again:", choice);
    }
    EATLINE;

    return choice;
}

void get_input(char *input)
{
    puts("Enter the string you want to handle:");
    while (s_gets(input, INPUTSTR)==NULL && input[0]=='\0')
    {
        puts("The empty string!");
    }
    puts("The initial string:");
    puts(input);
}

void to_lower(char *str)
{
    while (*str != '\0')
    {
        *str = tolower(*str);
        str++;
    }
}

void to_upper(char *str)
{
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}

void transform(char *str)
{
    while (*str != '\0')
    {
        if (islower(*str))
        {
            *str = toupper(*str);
        }
        else if(isupper(*str))
        {
            *str = tolower(*str);
        }
        str++;
    }
}

char * s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\0' && *str!='\n')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            EATLINE;
        }
    }
    return ptr;
}