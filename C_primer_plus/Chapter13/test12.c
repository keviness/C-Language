/*** Chapter13: test12 ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ROW 20
#define COLUM 30
#define NAME 20

void HandleCharacters(FILE *pf_source, char (*poiter_source)[COLUM], char(*pointer_target)[COLUM+1], int rows, int colums, char *str);
char *s_gets(char *str, int num);

int main(void)
{
    FILE *pf_source;
    FILE *pf_target;
    int i, j;
    char source_name[NAME];
    char target_name[NAME];
    char source[ROW][COLUM];
    char target[ROW][COLUM+1];
    char *ch = " .':~*= %#";

    puts("Enter the source file name:");
    s_gets(source_name, NAME);

    if ((pf_source = fopen(source_name, "r")) == NULL)
    {
        printf("The file: %s can\'t be opend.\n", source_name);
        exit(EXIT_FAILURE);
    }
/*
    for (i=0; i<ROW; i++)
    {
        for (j=0; j<COLUM; j++)
        {
            if (fscanf(pf_source, "%d", &source[i][j]) == 1)
            {
                target[i][j] = ch[source[i][j]];
            }
        }
        target[i][j] = '\0';
    }
*/
    HandleCharacters(pf_source, source, target, ROW, COLUM, ch);

    puts("Enter the target file name:");
    s_gets(target_name, NAME);
    if ((pf_target = fopen(target_name, "w")) == NULL)
    {
        printf("The file: %s can\'t be opend.\n", target_name);
        exit(EXIT_FAILURE);
    }
    puts("The file content:");
    for (i=0; i<ROW; i++)
    {
        fprintf(stdout, "%s\n", target[i]);
        fprintf(pf_target, "%s\n", target[i]);
    }
    if (fclose(pf_source)!=0 || fclose(pf_target)!=0)
    {
        printf("Error in closing these files\n");
        exit(EXIT_FAILURE);
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
        {
            str++;
        }
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

void HandleCharacters(FILE *pf_source, char (*ptr_source)[COLUM], char(*ptr_target)[COLUM+1], int rows, int colums, char *str)
{
    int i, j;

    for (i=0; i<rows; i++)
    {
        for (j=0; j<colums; j++)
        {
            if (fscanf(pf_source, "%d", &ptr_source[i][j]) == 1)
            {
                if ((i>0 && i<rows-1) && (j>0 && j<colums-1))
                {
                    if (abs(ptr_source[i][j]-ptr_source[i-1][j])>1 && abs(ptr_source[i][j]-ptr_source[i+1][j])>1 && abs(ptr_source[i][j]-ptr_source[i][j-1])>1 && abs(ptr_source[i][j]-ptr_source[i][j+1])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i-1][j]+ptr_source[i+1][j]+ptr_source[i][j-1]+ptr_source[i][j+1])/4);
                }
                if (i==0 && (j>0 && j<colums-1))
                {
                    if (abs(ptr_source[i][j]-ptr_source[i][j-1])>1 && abs(ptr_source[i][j]-ptr_source[i][j+1])>1 && abs(ptr_source[i][j]-ptr_source[i+1][j])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i][j-1]+ptr_source[i][j+1]+ptr_source[i+1][j])/3);
                }
                if (i==rows-1 && (j>0 && j<colums-1))
                {
                    if (abs(ptr_source[i][j]-ptr_source[i][j-1])>1 && abs(ptr_source[i][j]-ptr_source[i][j+1])>1 && abs(ptr_source[i][j]-ptr_source[i+1][j])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i][j-1]+ptr_source[i][j+1]+ptr_source[i+1][j])/3);
                }
                if (j==0 && (i>0 && i<rows-1))
                {
                    if (abs(ptr_source[i][j]-ptr_source[i-1][j])>1 && abs(ptr_source[i][j]-ptr_source[i+1][j])>1 && abs(ptr_source[i][j]-ptr_source[i][j+1])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i-1][j]+ptr_source[i+1][j]+ptr_source[i][j+1])/3);
                }
                if (j==colums-1 && (i>0 && i<rows-1))
                {
                    if (abs(ptr_source[i][j]-ptr_source[i-1][j])>1 && abs(ptr_source[i][j]-ptr_source[i+1][j])>1 && abs(ptr_source[i][j]-ptr_source[i][j-1])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i-1][j]+ptr_source[i+1][j]+ptr_source[i][j-1])/3);
                }
                if (i==0 && j==0)
                {
                    if (abs(ptr_source[i][j]-ptr_source[i+1][j])>1 && abs(ptr_source[i][j]-ptr_source[i][j+1])>1)
                    {
                        ptr_source[i][j] = (int)rintf((ptr_source[i+1][j]+ptr_source[i][j+1])/2);
                    }
                }
                if (i==0 && j==colums-1)
                {
                    if (abs(ptr_source[i][j]-ptr_source[i][j-1])>1 && abs(ptr_source[i][j]-ptr_source[i+1][j])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i][j-1]+ptr_source[i+1][j])/2);
                }
                if (i==rows-1 && j==0)
                {
                    if (abs(ptr_source[i][j]-ptr_source[i-1][j])>1 && abs(ptr_source[i][j]-ptr_source[i][j+1])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i-1][j]+ptr_source[i][j+1])/2);
                }
                if (i==rows-1 && j==colums-1)
                {
                    if (abs(ptr_source[i][j]-ptr_source[i-1][j])>1 && abs(ptr_source[i][j]-ptr_source[i][j-1])>1)
                        ptr_source[i][j] = (int)rintf((ptr_source[i-1][j]+ptr_source[i][j+1])/2);
                }
                ptr_target[i][j] = str[ptr_source[i][j]];
            }
        }
        ptr_target[i][j] = '\0';
    }
}