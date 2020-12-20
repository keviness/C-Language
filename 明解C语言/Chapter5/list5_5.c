#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAXLVEL  10
#define MINLEVEL 3
#define MAXSTAEG 5

int sleep(unsigned long mins);

int main(void)
{
    int success = 0;
    int stage;
    int level;
    clock_t start, end;
    const char alpha[] = "abcdefghijklmnopqrstuvwxyz"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    do
    {
        printf("Enter the level you want to guess:");
        scanf("%d", &level);
    }while (level<MINLEVEL || level>MAXLVEL);
    
    srand(time(NULL));
    printf("The %d level you have chosen.\n");

    start = clock();
    for (int i=0; i<MAXSTAEG; i++)
    {
        char randomStr[MAXLVEL+1];
        char guessStr[MAXLVEL * 2];
        for (int j=0; j<level; j++)
            randomStr[j] = alpha[rand()%strlen(alpha)];

        randomStr[level] = '\0';
        printf(randomStr);
        fflush(stdout);
        sleep(125 * level);

        printf("\r*s\r enter your guess please:", level, "");
        fflush(stdout);
        scanf("%s", guessStr);

        if (strcmp(randomStr, guessStr) != 0)
            printf("The error \n");
        else
        {
            printf("guess successfully!\n");
            success++;
        }
    }
    end = clock();
    printf("%d guess success times in %d stages! \n", success, stage);
    printf("spend %4.2f times\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

int sleep(unsigned long mins)
{
    clock_t c1 = clock(), c2;

    do
    {
        if ((c2 = clock()) == (clock_t)-1)
        {
            return 0;
        }
    } while ((c2-c1)*1000.0/CLOCKS_PER_SEC < mins);
    
    return 1;
}