/*** Chapter16: exercise4 ***/
#include <stdio.h>
#include <string.h>
#define NAMESIZE 20
#define SIZE 5

typedef struct  person_info
{
    char last_name[NAMESIZE];
    char middle_name[NAMESIZE];
    char first_name[NAMESIZE];
}person;

typedef struct asurance_info
{
    int asurance_code;
    person names;
}assurance;

void print_info_a(assurance *ptr);
void print_info_b(assurance people);
int main(void)
{
    assurance peoples[SIZE] = {
        {12, {"kevin", "MI", "lake"}},
        {16, {"Nancy", "NI", "Lucy"}},
        {32, {"merry", "G", "john"}},
        {234, {.first_name="bonn", .last_name="Hery"}},
        {45, {.first_name="Harry", .last_name="Reht"}}
    };

    puts("The informations you input:");
    for (int i=0; i<SIZE; i++)
    {
        print_info_a(&peoples[i]);
    }
    for (int i=0; i<SIZE; i++)
    {
        print_info_b(peoples[i]);
    }

    return 0;
}

void print_info_a(assurance *ptr)
{
    printf("%s, %s ", ptr->names.first_name, ptr->names.last_name);
    if (ptr->names.middle_name[0] != '\0')
    {
        printf("%c. ", ptr->names.middle_name[0]);
    }
    printf("-- %d \n", ptr->asurance_code);
}

void print_info_b(assurance people)
{
    printf("%s, %s ", people.names.first_name, people.names.last_name);
    if (people.names.middle_name[0] != '\0')
    {
        printf("%c. ", people.names.middle_name[0]);
    }
    printf("-- %d \n", people.asurance_code);
}
