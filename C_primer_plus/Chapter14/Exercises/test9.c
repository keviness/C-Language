/*** Chapter14: test9 ***/
//add top menu
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define NAMESIZE 20
#define MAXSIZE 12
#define FLIGHTNUM 4
#define EATLINE while(getchar()!='\n')continue

typedef struct seat
{
    int seat_code;
    char first_name[NAMESIZE];
    char last_name[NAMESIZE];
    bool isassigned;
}SEAT;


typedef struct flight
{
    char flight_number[FLIGHTNUM];
    SEAT seats[MAXSIZE];
}FLIGHT;

FLIGHT flights[FLIGHTNUM];

int size = sizeof(FLIGHT);
bool iscomfirm = false;
FLIGHT *pflight;

char get_flight(void);
char get_choice(void);
void initialize(FLIGHT *pst);
FILE * readfile(FLIGHT *pst, int argc ,char *argv[]);
void writefile(FILE *pf, FLIGHT *pst);
void show_empty_number(SEAT *pst);
void show_empty_list(SEAT *pst);
void show_alpha_list(SEAT *pst);
void assign_seat(SEAT *pst);
void delete_seat(SEAT *pst);
void confirm_select(void);
char *s_gets(char *str, int num);

int main(int argc, char *argv[])
{
    
    char flight_choice, seat_choice;
    FILE * pf;
    
    initialize(flights);
    pf = readfile(flights, argc, argv);
    while ((flight_choice = get_flight()) != 'q')
    {
        iscomfirm = false;
        while ((seat_choice = get_choice()) != 'g')
        {
            switch (seat_choice)
            {
                case 'a':
                case 'A':show_empty_number(pflight->seats);
                    break;
                case 'b':
                case 'B':show_empty_list(pflight->seats);
                    break;
                case 'c':
                case 'C':show_alpha_list(pflight->seats);
                    break;
                case 'd':
                case 'D':assign_seat(pflight->seats);
                    break;
                case 'e':
                case 'E':delete_seat(pflight->seats);
                    break;
                case 'f':
                case 'F':confirm_select();
                    break;
                default:puts("The choice is error!");
                    break;
            }
        }
        if (iscomfirm)
        {
            writefile(pf, flights);
        }
    }
    puts("The Done~");
    return 0;
}

void initialize(FLIGHT *pst)
{
    int i, j;

    for (i=0; i<FLIGHTNUM; i++)
    {
        for (j=0; j<MAXSIZE; j++)
        {
            pst[i].seats[j].seat_code = j+1;
            strcpy(pst[i].seats[j].first_name, "");
            strcpy(pst[i].seats[j].last_name, "");
            pst[i].seats[j].isassigned = false;
        }
    }
}

FILE * readfile(FLIGHT *pst, int argc, char *argv[])
{
    FILE *pf;
    int count;
    if (argc < 2)
    {
        printf("Usage: The program must need two arguments, only %d given.\n", argc-1);
        exit(EXIT_FAILURE);
    }
    if ((pf = fopen(argv[1], "a+")) == NULL)
    {
        printf("Usage: The %s file can\'t be opened! \n");
        exit(EXIT_FAILURE);
    }
    if (count = fread(pst, size, FLIGHTNUM, pf))
    {
        printf("From the file has read %d items. \n", count);
    }
    return pf;
}

char get_flight(void)
{
    char choice;
    puts("Enter your flight choice:");
    puts("a) 102        b) 311");
    puts("c) 444        d) 519");
    puts("q) quit");
    while (((choice=getchar())<'a' || choice>'d') && choice!='q')
    {
        puts("The flight choice is error! try again:");
        EATLINE;
    }
    EATLINE;
    switch (choice)
    {
        case 'a': 
        case 'A':pflight = &flights[0];
                strcpy(pflight->flight_number, "102");
            break;
        case 'b':
        case 'B': pflight = &flights[1];
                  strcpy(pflight->flight_number, "311");
            break;
        case 'c':
        case 'C': 
                  pflight = &flights[2];
                  strcpy(pflight->flight_number, "444");
            break;
        case 'd':
        case 'D': pflight = &flights[3];
                  strcpy(pflight->flight_number, "519");
            break;
        case 'q':
        case 'Q':break;
        default: printf("The flight choice is error! \n");
            break;
    }

    return choice;
}

char get_choice(void)
{
    char choice;

    puts("****************************");
    puts("Enter your seats choice:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat");
    puts("e) Delete a seat assignment");
    puts("f) confirm the seat");
    puts("g) return main menu");
    puts("*****************************");
    while ((choice = getchar())<'a' || choice>'g')
    {
        EATLINE;
        puts("The choice you input is error! try again:");
    }
    EATLINE;

    return choice;
}

void writefile(FILE *pf, FLIGHT *pst)
{
    int count;
    if (count = fwrite(pst, size, FLIGHTNUM, pf))
    {
        printf("There are %d items has been write in file.\n", count);
    }

    if (fclose(pf) != 0)
    {
        printf("The file closed error! \n");
    }
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

void show_empty_number(SEAT *pst)
{
    int count = 0;
    printf("In %s flight: \n", pflight->flight_number);
    for (int i=0; i<MAXSIZE; i++)
    {
        if (!pst[i].isassigned)
        {
            count++;
        }
    }
    printf("There are %d items isn\'t selected. \n", count);
}

void confirm_select(void)
{
    iscomfirm = true;
    printf("The selected seat has been confirmed. \n");
}

void show_empty_list(SEAT *pst)
{
    printf("In %s flight: \n", pflight->flight_number);
    for (int i=0; i<MAXSIZE; i++)
    {
        if (!pst[i].isassigned)
        {
            printf("The number %d seat has not been selected. \n", pst[i].seat_code);
        }
    }
}

void show_alpha_list(SEAT *pst)
{
    printf("In %s flight: \n", pflight->flight_number);
    for (int i=0; i<MAXSIZE; i++)
    {
        if (pst[i].isassigned)
        {
            printf("number:%d first name:%s last name:%s \n", pst[i].seat_code, pst[i].first_name, pst[i].last_name);
        }
    }
    puts("These items has not been comfirmed.");
}

void assign_seat(SEAT *pst)
{
    int number, ch, rest;
    SEAT temp;
    printf("In %s flight: \n", pflight->flight_number);
    puts("Enter the seat number you want to assign:");

    while ((rest = scanf("%d", &number)!=1) || number<1 || number>12 || pst[number-1].isassigned)
    {
        if (number<1 || number>12 || rest!=1)
        {
            printf("The number is out of range. try again: \n");
            continue;
        }
        else
        {
            printf("The %d seat has been selected. choose again: \n", pst[number]);
            continue;
        }
        EATLINE;
    }
    EATLINE;

    puts("Enter the first name:");
    s_gets(temp.first_name, NAMESIZE);
    puts("Enter the last name:");
    s_gets(temp.last_name, NAMESIZE);
    temp.isassigned = true;

    puts("Are you sure to save in the file?(y/n)");
    if ((ch=getchar()) != '\n')
        EATLINE;
    if (ch=='n' || ch=='N')
    {
        printf("Aborting to save in the file. \n");
        return;
    }
    pst[number-1] = temp;
    puts("Save Successfully!");
}

void delete_seat(SEAT *pst)
{
    int number, ch, rest;
    printf("In %s flight: \n", pflight->flight_number);
    puts("Enter the number you want to delete:");
    while ((rest = scanf("%d", &number))!=1 || number<1 || number>12 || !pst[number-1].isassigned)
    {
        if (rest!=1 || number<1 || number>12)
        {
            printf("The number seat you input out of range. try again:\n");
            continue;
        }
        else
        {
            printf("The %d seat has not been seleced. try again:\n", number);
            continue;
        }
        EATLINE;
    }
    EATLINE;

    puts("Are you sure to selete this item?(y/n):");
    if ((ch = getchar()) != '\n')
    {
        EATLINE;
    }
    if (ch=='n' || ch=='N')
    {
        puts("Aborting to delete this item.");
        return;
    }
    pst[number-1].isassigned = false;
    strcpy(pst[number-1].first_name, "");
    strcpy(pst[number-1].last_name, "");
    printf("delete successfully! \n");
}
