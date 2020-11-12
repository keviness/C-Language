#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 10

int main(void)
{
    int record[SIZE];
    int times = 0;
    srand(time(NULL));
    int randomNumber = rand()%21;
    int guess;

    puts("Enter the number that you guess:");
    do
    {
        scanf("%d", &guess);
        if (guess < randomNumber)
        {
            printf("The number you guess is less than the number! try again: \n");
        }
        if (guess > randomNumber)
        {
            printf("THe number you guess is more than the random number! try again: \n");
        }
        record[times++] = guess;
    } while (guess!=randomNumber && times<SIZE);
    if (guess == randomNumber)
        printf("Congulation! you use %d times chances to guess the number! \n", times);
    else
    {
        printf("Sorry! the game is over! \n");
    }

    puts("The detail of the game:");
    for (int i=0; i<times; i++)
    {
        printf("%d\n", record[i]);
    }
    
    return 0;
}