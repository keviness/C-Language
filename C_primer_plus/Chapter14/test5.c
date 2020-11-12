/*** test5 ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAME 10
#define GRADE 3
#define MAXSIZE 40
char *s_gets(char *str, int n);

struct name{
    char first_name[NAME];
    char last_name[NAME];
};
struct student{
    struct name info;
    float grade[GRADE];
    float average;
};
void handle_line(void);
void get_info(struct student *pst[], int n);
void show_info(struct student *pst[], int n);
float cal_average(struct student *pst[], int n);
void show_avg(struct student *pst[], int n);
int main(void)
{
    struct student *pst[MAXSIZE];
    struct student students[MAXSIZE];
    int count = 0;
    puts("Enter your first name:");
    while (count<MAXSIZE && s_gets(students[count].info.first_name, NAME)\
    && students[count].info.first_name[0]!='\0')
    {
        puts("Enter your last name:");
        s_gets(students[count].info.last_name, NAME);
        puts("Enter your grade:");
        for (int i=0; i<GRADE; i++)
        {
            scanf("%f", &(students[count]).grade[i]);
            handle_line();
            if (i < GRADE-1)
                puts("Enter the next grade:");
        }
        pst[count] = &students[count];
        count++;

        if (count < MAXSIZE)
            puts("Enter the first name:");
    }
    puts("The informations:");
    show_info(pst, count);
    show_avg(pst, count);
    puts("The done~");

    return 0;
}

void handle_line(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void show_info(struct student *pst[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("The name of the student:%s %s \n", (pst[i]->info).first_name, (pst[i]->info.last_name));
        printf("The grade of the student:%f \n", pst[i]->grade[i]);
    }
}

float cal_average(struct student *pst[], int num)
{
    float total, average;
    for (int i=0; i<num; i++)
    {
        for (int j=0; j<GRADE; j++)
            total += (pst[i]->grade[j]);
    }
    average = total/num;
    return average;
}

void show_avg(struct student *pst[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("The student: %s, the average:%f \n", pst[i]->info.first_name,\
        pst[i]->average);
    }
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
                continue;
        }
    }
    return ptr;
}