#include <stdio.h>
#include <string.h>
#define LIM 10
#define SIZE 30
int get_strings(char *ptr[], char (*str)[], int m);
int count_first(char *st);
char *s_gets(char *st, int n);
char get_choice(void);
char get_first(void);
void put_strings(char *st[]);
void put_asci(char *st[], int n);
void put_length(char *st[], int n);
void put_first(char *st[], int n);
int main(void)
{
    char input[LIM][SIZE];
    char *ptr[LIM];
    unsigned int ch;
    int num;
    num = get_strings(ptr, input, LIM);
    while ((ch=get_choice())!='Q' && ptr!=NULL)
    {
        if (ch<'A' && ch>'D')
        {
            puts("The input choice is wrong try again");
            continue;
        }
        switch (ch)
        {
            case 'A': put_strings(ptr);
                    break;
            case 'B': put_asci(ptr, num);
                    break;
            case 'C': put_length(ptr, num);
                    break;
            case 'D': put_first(ptr, num);
                    break;
            default: puts("The programmer error!");
                    break;
        }
    }
    puts("The Done~");

    return 0;
}
char *s_gets(char *st, int num)
{
    char *ptr;
    ptr = fgets(st, num, stdin);
    if (ptr)
    {
        while (*st!='\n' && *st!='\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}
int get_strings(char *ptr[], char (*str)[SIZE], int num)
{
    int i = 0;
    puts("Enter the letters:");
    printf("Please enter the %dth strings: \n", i+1);
    while (i<num && s_gets(str[i], SIZE) && str[i][0]!='\0')
    {
        ptr[i] = str[i];
        i++;
        printf("Please enter the %dth strings: \n", i+1);
    }
    return i;
}
char get_choice(void)
{
    unsigned int ch;
    puts("Enter your choice:");
    puts("A.print origin strings     B.print strings with ASCII");
    puts("C.print strings with length  D.print strings with first word");
    puts("Q.quit");
    ch = get_first();
    return ch;
}
char get_first(void)
{
    unsigned int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch; 
}
void put_strings(char *str[])
{
    while (*str)
    {
        puts(*str);
        str++;
    }
}
void put_asci(char *str[], int num)
{
    int top, seek;
    char *temp;
    for (top=0; top<num-1; top++)
        for (seek=1; seek<num; seek++)
        {
            if (strcmp(str[top], str[seek]) > 0)
            {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        }
    put_strings(str);
}
void put_length(char *str[], int num)
{
    char *temp;
    int top, seek;
    for (top=0; top<num-1; top++)
        for (seek=1; seek<num; seek++)
        {
            if (strlen(str[top]) > strlen(str[seek]))
            {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        } 
    put_strings(str);
}
void put_first(char *str[], int num)
{
    char *temp;
    int top, seek;
    for (top=0; top<num-1; top++)
        for(seek=1; seek<num; seek++)
        {
            if (count_first(str[top])>count_first(str[seek]))
            {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        }
    put_strings(str);
}
int count_first(char *str)
{
    int ct;
    while (*str!='\0' && *str!=' ')
    {
        ct++;
        str++;
    }
    return ct;
}

