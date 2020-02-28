/***diceroll***/
#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollme(int sides)
{
    int roll;
    roll = rand() % sides + 1;
    roll_count++;
    return roll;
}
int roll_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("need at least 2 sides\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 dicerool \n");
        return -1;
    }
    for (d=0; d<dice; d++)
    {
        total += rollme(sides);
    }
    return total;
}