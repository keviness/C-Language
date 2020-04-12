/*** function pointer ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 90

char * s_gets(char *st, int n);
void ToUpper(char *st);
void ToLower(char *st);
void Transform(char *st);
void Dump(char *st);
void show_str(char *st);
char show_menu(void);
void line_handle(void);
void run_function(void (*ptf)(char*), char*st);

int main(void)
{
    char letter[LENGTH];
    char copy[LENGTH];
    void (*ptf)(char *);
    char choice;

    puts("Enter your string:");
    while (s_gets(letter, LENGTH) && letter[0]!='\0')
    {
        puts("The orignal string:");
        show_str(letter);
        while ((choice=show_menu())!='n')
        {
            switch (choice)
            {
                case 'o': ptf = Dump; break;
                case 'u': ptf = ToUpper; break;
                case 'l': ptf = ToLower; break;
                case 't': ptf = Transform; break;
                default:
                    puts("The program error!");
                    break;
            }
            strcpy(copy, letter);
            run_function(ptf, copy);
        }
        puts("Enter the next string:");
    }
    puts("The done~");

    return 0;
}

char show_menu(void)
{
    char choice;
    puts("Enter your choice:");
    puts("u.ToUpper         l.ToLower");
    puts("t.Transform       o.Dump");
    puts("n.quit");
    choice = getchar();
    choice = tolower(choice);
    line_handle();
    while (strchr("ulton", choice) == NULL)
    {
        puts("The choice you input is wrong, try again:");
        choice = getchar();
        choice = tolower(choice);
        line_handle();
    }
    return choice;
}

void line_handle(void)
{
    while (getchar() != '\n')
        continue;
}

void show_str(char *str)
{
    while (*str)
    {
        putchar(*str);
        str++;
    }
    putchar('\n');
}

void Dump(char *str)
{
    puts("No thing to change, the original string:");
}

void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transform(char *str)
{
    while (*str)
    {
        if (islower(*str))
        {
            *str = toupper(*str);
        }
        else if (isupper(*str))
        {
            *str = tolower(*str);
        }
        str++;
    }
}

void run_function(void (*ptf)(char *), char *str)
{
    (*ptf)(str);
    puts(str);
    puts("*********");
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
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}