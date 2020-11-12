/*** save struct type in file ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITLE 30
#define MAXAUTHOR 30
#define MAXSIZE 10
char *s_gets(char *str, int n);
struct book{
    char title[MAXTITLE];
    char author[MAXAUTHOR];
    double value;
};

int main(int argc, char *argv[])
{
    FILE *fp;
    struct book library[MAXSIZE];
    int count = 0;
    int filecount;
    int size = sizeof(struct book);
    if (argc < 2)
    {
        printf("Usage:The %s program need two argumens.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "a+b")) == NULL)
    {
        printf("Usage:The %s file can\'t open. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    while (fread(&library[count], size, 1, fp)==1 && count<MAXSIZE)
    {
        if (count==0)
        {
            puts("The library content:");
        }
        printf("The book title:%s \n", library[count].title);
        printf("The book of the author:%s \n", library[count].author);
        printf("The value of the book:%lf \n", library[count].value);
        
        count++;
    }
    filecount = count;
    if (count == MAXSIZE)
    {
        printf("The %s file is full. \n", argv[1]);
        exit(EXIT_FAILURE);
    }

    puts("Enter the title of the new book:");
    while (count<MAXSIZE && s_gets(library[count].title, MAXTITLE) && library[count].title[0]!='\0')
    {
        puts("Enter the name of the author:");
        s_gets(library[count].author, MAXAUTHOR);
        puts("Enter the value of the book:");
        scanf("%g", &library[count].value);
        while (getchar() != '\n')
        {
            continue;
        }
        puts("Enter the next title of the new book:");
        count++;
    }

    if (count > 0)
    {
        puts("The information of the library:");
        for (int i=0; i<count; i++)
        {
            printf("The %s book by %s value: %g .\n", library[i].author, library[i].author, library[i].value);
        }
        if (fwrite(&library[filecount], size, count-filecount, fp) != (count-filecount))
        {
            printf("Usage:Error in writing data in %s file.\n", argv[1]);
        }
    }
    else
    {
        puts("That is bad, NO books.");
    }
    if (fclose(fp) != 0)
    {
        printf("Usage:Error in closing the %s file. \n", argv[1]);
    }
    
    return 0;
}

char *s_gets(char *str, int num)
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
            {
                continue;
            }
        }
    }
    return ptr;
}
