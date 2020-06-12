/*** Chapter14 test7 ***/
//modify the example14.14
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 10
#define MAXNAME 40
#define EATLINE while (getchar() != '\n') continue

typedef struct books
{
    char title[MAXNAME];
    char author[MAXNAME];
    double value;
}BOOK;

void printContent(BOOK *pst);
char *getStr(char *str, int num);
void editContent(BOOK *pst);
void deleteContent(BOOK *pst);
int getChoice(void);

int main(int argc, char *argv[])
{
    BOOK library[MAXSIZE];
    int count = 0;
    FILE *pf;
    int size = sizeof(BOOK);

    if (argc < 2)
    {
        printf("Usage: This program must given 2 arguments, only %d given \n", argc-1);
        exit(EXIT_FAILURE);
    }    
    if ((pf = fopen("book.dat", "ab+")) == NULL)
    {
        fprintf(stderr, "Usage: The %s file can\'t be opened! \n", argv[1]);
        exit(EXIT_FAILURE);
    }

    puts("The current content of the file:");
    while (count<MAXSIZE && fread(&library[count], size, 1, pf)==1)
    {
        int choice;

        puts("The information of the file:");
        printContent(&library[count]);
        choice = getChoice();
        switch (choice)
        {
            case 'n':
            case 'N':
                break;
            case 'm':
            case 'M':
                editContent(&library[count]);
                break;
            case 'd':
            case 'D':
                count--; //将前者覆盖了，也就相当于前者被删除了
                break;
            default:
                break;
        }
        count++;
    }

    if (fclose(pf) != 0)
    {
        printf("Usage: The file %s can\'t close!", argv[1]);
        exit(EXIT_FAILURE);
    }

    puts("The information of the file currently:");
    if (count == 0)
    {
        puts("The file is empty!");
    }
    else
    {
        for (int i=0; i<count; i++)
        {
            printContent(&library[i]);
        }
    }
    
    

    if (count == MAXSIZE) 
    {
        printf("Usage: The file is full!");
        exit(EXIT_SUCCESS);
    }
    else
    {
        puts("please enter the new book title:");
        while (count<MAXSIZE && getStr(library[count].title, MAXNAME) && library[count].title[0]!='\0')
        {
            puts("Enter the author name:");
            getStr(library[count].author, MAXNAME);
            puts("Enter the value:");
            scanf("%lf", &library[count].value);
            count++;

            if (count < MAXSIZE)
            {
                puts("Enter the next new book title:");
            }
        }
    }
    
    if ((pf = fopen("book.dat", "wb")) == NULL)
    {
        printf("Usage: The file %s can't opened!", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (count > 0)
    {
        fwrite(library, size, count, pf);
        for (int i=0; i<count; i++)
        {
            printContent(&library[i]);
        }
    }

    if (fclose(pf) != 0)
    {
        printf("Usage: The file can\'t closed!");
        exit(EXIT_FAILURE);
    }

    return 0;
}

int getChoice(void)
{
    int ch;
    puts("Enter the choice:");
    puts("[n]next record    [d]delete this record");
    puts("[m]modify this record");
    ch = getchar();
    EATLINE;

    return ch;
}

void printContent(BOOK *pst)
{
    printf("Title: %s \n", pst->title);
    printf("Author: %s \n", pst->author);
    printf("Value: %lf \n", pst->value);
}

void editContent(BOOK *pst)
{
    puts("Enter the book title:");
    getStr(pst->title, MAXNAME);
    puts("Enter the book author name:");
    getStr(pst->author, MAXNAME);
    puts("Enter the book value:");
    scanf("%lf", pst->title);
    EATLINE;
}

void deleteContent(BOOK *pst)
{
    if (pst)
    {
        free(pst->author);
        free(pst->title);
        free(&(pst->value));
    }
}

char *getStr(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
        {
            str++;
        }
        if (*str == '\n')
        {
            *str = '\0';
        }
        else
        {
            EATLINE;
        } 
    }
    return ptr;
}