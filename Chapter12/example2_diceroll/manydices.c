/***many dices***/
#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"
#include <time.h>
int main(void)
{
    int dice, roll;
    int status;
    int sides;
    char ch;
    srand((unsigned int) time(0));
    printf("Enter the dice per sides, 0 to stop: \n");
    while (sides>0 && scanf("%d", &sides))
    {
        printf("How many dices: \n");
        if (status = scanf("d", &dice) != 1)
        {
            if (status == EOF)
                break;
            else 
            {
                while ((ch=getchar()) != '\n')
                {
                    putchar(ch);
                }
                printf(" is not a interrge, please try again!");
                continue;
            }
        }
        roll = roll_dice(dice, sides);
        printf("You are get %d, by using %d dices with %d-sides dices.\n", roll, dice, sides);
        printf("How many sides, 0 to quit: \n");
    }
    printf("The rollme() has been called %d times \n", roll_count);
    printf("Good fortune to you~ \n");

    return 0;
}