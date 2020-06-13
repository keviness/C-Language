/*** Chapter14 test8 ***/
//seat struct handle
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define EATLINE while(getchar() != '\n') continue
#define MAXSIZE 12
#define NAMESIZE 20

typedef struct seat_info
{
    int seat_code;
    bool selected;
    char custom_first[NAMESIZE];
    char custom_last[NAMESIZE];
}SEATINFO;

SEATINFO seats[MAXSIZE];

int get_choice(void);
void show_emptycode(void);
void show_emptylist(void);
void show_alphalist(void);
void assign_seat(void);
void delete_seat(void);
char *get_str(char *str, int num);

int main(int argc, char *argv[])
{
    FILE *pf;
    int count = 0;
    int choice;
    int size = sizeof(SEATINFO);

    if (argc < 2)
    {
        printf("Usage: The %s program must given two arguments, only %d given. \n", argv[0], argc-1);
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<MAXSIZE; i++)
    {
        seats[i].seat_code = i+1;
        seats[i].selected = false;
    }

    if ((pf = fopen("seat.txt", "a+")) == NULL)
    {
        printf("Usage: The file %s can\'t be opend.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fread(&seats[count], size, 1, pf) == 1)
    {
        count++;
    }

    while ((choice=get_choice()) != 'f')
    {
        switch (choice)
        {
        case 'a':
        case 'A': show_emptycode();
            break;
        case 'B':
        case 'b': show_emptylist();
            break;
        case 'C':
        case 'c': show_alphalist();
            break;
        case 'd': 
        case 'D': assign_seat();
            break;
        case 'e':
        case 'E': delete_seat();
            break;
        case 'F':
        case 'f': 
            break;
        default:
            break;
        }
    }

    return 0;
}

int get_choice(void)
{
    int choice;
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat");
    puts("e) Delete a seat assignment");
    puts("f) quit");

    choice = getchar();
    EATLINE;

    return choice;
}

void show_emptycode(void)
{
    int count = 0;
    for (int i=0; count<MAXSIZE; i++)
    {
        if (!seats[count].selected)
        {
            count++;
        }
    }
    printf("There are %d seats is empty!", count);
}

void show_emptylist(void)
{
    int count = 0;
    for (count=0; count<MAXSIZE; count++)
    {
        if (!seats[count].selected)
        {
            printf("The %d seat is empty! \n", seats[count].seat_code);
        }
    }
}

void show_alphlist(void)
{
    printf("%-*s %-*s %-*s \n", NAMESIZE, "first name", NAMESIZE, "last name", NAMESIZE, "seat number");

    for (int i=0; i<MAXSIZE; i++)
    {
        if (seats[i].selected)
        {
            printf("%-*s %-*s %-*d \n", NAMESIZE, seats[i].custom_first,\
            NAMESIZE, seats[i].custom_last, NAMESIZE, seats[i].seat_code);
        }
    }
}

void assign_seat(void)
{
    SEATINFO new;
    int choice, code, ch;

    while (scanf("%d", &code) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a number, try again: \n");
    }
    if (code<0 || code>MAXSIZE)
    {
        printf("The seat: %d is not a corrent code. \n", code);
        return;
    }
    if (seats[code].selected)
    {
        printf("The seat: %d has been selected. \n", code);
        return;
    }

    puts("Enter the customer\'s first name:");
    get_str(new.custom_first, NAMESIZE);
    puts("Enter the customer\'s last name:");
    get_str(new.custom_last, NAMESIZE);
    new.selected = true;
    new.seat_code = code;
    printf("Seat number:%d customer first name:%s, customer last name:%s \n", 
    new.seat_code, new.custom_first, new.custom_last);
    puts("Are you sure to add the customer:(y/n)");
    if ((ch = getchar()) != '\n')
    {
        EATLINE;
    }
    if (ch == 'n' || ch == 'N')
    {
        printf("Aborting seat assignment. \n");
        return;
    }
    seats[code] = new;
}

void delete_seat(void)
{
    int code, choice, ch;
    while ((code = scanf("%d", &code)) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a number, try again: \n");
    }
    if (code<0 || code>MAXSIZE)
    {
        printf("The code: %d you input is not corrently! \n", code);
        return;
    }
    if (!seats[code].selected)
    {
        printf("The code %d seat has not been selected! \n", code);
        return;
    }

    printf("Seat number:%d customer first name:%s last name:%s \n", seats[code].seat_code, seats[code].custom_first,\
    seats[code].custom_last);
    puts("Are you sure to delete this item?(n/y):");
    while ((choice = getchar()) != '\n')
    {
        EATLINE;
    }
    if (choice!='n' || choice!='N')
    {
        printf("Aborting delete seat. \n");
        return;
    }
    seats[code].custom_first[0] = '\0';
    seats[code].custom_last[0] = '\0';
    seats[code].selected = false;
    
}