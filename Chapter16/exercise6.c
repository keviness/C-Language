/*** Chapter16: exercise6 ***/
//compare string by qsort() function

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 30
#define NUM 10
#define CLEARLINE while(getchar()!='\n')continue

typedef struct NAMES
{
    char first_name[MAXSIZE];
    char last_name[MAXSIZE];
}name;

int compareString(const void *ptr1, const void *ptr2);
void printName(name arr[], int num);
void getName(name arr[], int num);

int main(void)
{
    name students[MAXSIZE];
    int num;
    puts("How many students:");
    while (scanf("%d", &num) == 1)
    {
        CLEARLINE;
        if (num <= 0)
        {
            puts("The number must more than zero! try again:");
            continue;
        }
        getName(students, num);
        puts("The students\' names you input:");
        printName(students, num);
        qsort(students, num, sizeof(name), compareString);
        puts("The result after quick sorted:");
        printName(students, num);

        puts("How many students:");
    }
    puts("The Done~");
    
    return 0;
}

void getName(name arr[], int num)
{
    
    for (int i=0; i<num; i++)
    {
        puts("Enter the first name of the student:");
        if (scanf("%s", arr[i].first_name) == 1)
        {
            CLEARLINE;
            puts("Enter the last name of the stdent:");
            while (scanf("%s", arr[i].last_name) != 1)
            {
                puts("The last name input error, try again:");
            }
        }
        else
        {
            puts("The first name input wrong, try again:");
            i--;
        }
    }
}

void printName(name arr[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("the %d student: %s  %s \n",i+1, arr[i].first_name, arr[i].last_name);
    }
}

int compareString(const void *ptr1, const void *ptr2)
{
    name *a = (name *)ptr1;
    name *b = (name *)ptr2;

    return strcmp(a->first_name, b->first_name)!=0? \
    strcmp(a->first_name, b->first_name):strcmp(a->last_name,b->last_name);
}