/*** names handle ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAMELINE 80
char * s_gets(char *st, int n);
/*
struct namect{
    char first[NAMELINE];
    char last[NAMELINE];
    int name_count;
};
*/
struct namect{
    char * first;
    char * last;
    int name_count;
};

void getinfo(struct namect *pst);            //struct pointer
void showinfo(const struct namect *pst);
void makeinfo(struct namect *pst);
void cleanup(struct namect *pst);

/*
struct namect getinfo(void);                 //struct type
void showinfo(struct namect);
struct namect makeinfo(struct namect);
*/

int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}

/*
void getinfo(struct namect *pst)
{
    puts("Enter your first name:");
    s_gets(pst->first, NAMELINE);
    puts("Enter your last name:");
    s_gets(pst->last, NAMELINE);
}
*/

void getinfo(struct namect *pst)
{
    char temp[NAMELINE];
    puts("Enter your first name:");
    s_gets(temp, NAMELINE);
    pst->first = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->first, temp);

    puts("Enter your last name:");
    s_gets(temp, NAMELINE);
    pst->first = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->last, temp);
}

void cleanup(struct namect *pst)
{
    free(pst->first);
    free(pst->last);
}

void makeinfo(struct namect *pst)
{
    pst->name_count = strlen(pst->first)+strlen(pst->last);
}

void showinfo(const struct namect *pst)
{
    puts("The information:");
    printf("The first name:%s \n",pst->first);
    printf("The last name:%s \n",pst->last);
    printf("The count of the name:%d", pst->name_count);
}

/*
int main(void)
{
    struct namect person;
    person = getinfo();
    person = makeinfo(person);
    showinfo(person);

}

struct namect getinfo(void)
{
    puts("Enter your first name:");
    struct namect temp;
    s_gets(temp.first, NAMELINE);
    puts("Enter your last name:");
    s_gets(temp.last, NAMELINE);
    return temp;
}

struct namect makeinfo(struct namect info)
{
    info.name_count = strlen(info.first) + strlen(info.last);
    return info;
}

void showinfo(struct namect info)
{
    puts("The information:");
    printf("The first name:%s \n", info.first);
    printf("The last name:%s \n", info.last);
    printf("The count of the name:%d \n", info.name_count);
}
*/

char * s_gets(char *st, int num)
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


