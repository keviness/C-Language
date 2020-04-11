/*** function pointer ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 90

char * s_gets(char *st, int n);
void ToUpper(char *st);
void Tolower(char *st);
void Transform(char *st);
void Dump(char *st);
void show_str(char *st);
char show_menu(void);
void run_function(void (*ptf)(char*), char*st);

int main(void)
{
    char letter[LENGTH];
    char copy[LENGTH];
    void (*ptf)(char *);
    char choice;

    puts("Enter your choice:");
    while (s_gets(letter, LENGTH) && letter[0]!='\0')
    {
        puts("The orignal string:");
        show_str(letter);
        while ((choice=show_menu())!='n')
        {
            switch (choice)
            {
            case 'n': ptf = Dump; break;
            case 'u': ptf = ToUpper; break;
            case 'l': ptf = Tolower; break;
            case 't': ptf = Transform; break;
            default:
                puts("The program error!");
                break;
            }
            strcpy(copy, letter);
            run_function(ptf, copy);
            show_str(copy);
        }
        puts("Enter the next string:");
    }
    puts("The done~");

    return 0;
}