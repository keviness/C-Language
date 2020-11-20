#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initialize(void);
void startgame(void);
void show_result(int num);
void count_times(int num);

int human;
int computer;
int win_times;
int lose_times;
int draw_times;

char *hands[] = {"ROCK", "SCISSORS", "PAPER"};

int main(void)
{
    int judge;
    initialize();
    do
    {
        startgame();
        printf("I start:%s, you start:%s. \n", hands[computer], hands[human]);

        judge = (human - computer + 3) % 3;
        count_times(judge);
        show_result(judge);
    } while (win_times<3 && lose_times<3);
    
    printf(win_times==3 ? "you win.\n" : "\n I win.\n");

    return 0;
}

void initialize(void)
{
    srand(time(NULL));
    win_times = 0;
    lose_times = 0;
    draw_times = 0;

    printf("The game start! \n");
}

void startgame(void)
{
    int i;

    computer = rand() % 3;
    do
    {
        printf("rock(0),scissor(1),paper(2)...:\n");
        for (i=0; i<3; i++)
        {
            printf("(%d)%s", i, hands[i]);
            printf(":");
            scanf("%d", &human);
        }
    }while (human<0 || human>2);
}

void count_times(int result)
{
    switch (result)
    {
        case 0: draw_times++; break;
        case 1: lose_times++; break;
        case 2: win_times++; break;
        default: printf("The program is wrong!\n");
    }
}

void show_resule(int result)
{
    switch (result)
    {
        case 0: printf("Draw \n"); break;
        case 1: printf("You lose \n"); break;
        case 2: printf("You win \n"); break;
        default: printf("The program wrong! \n");
    }
}