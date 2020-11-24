/***run Drivel***/
#include <stdio.h>
#include <stdlib.h>
extern unsigned int random(void);
extern void setSeed(unsigned int n);

int main(void)
{
    unsigned int seed;
    printf("Enter your seed: \n");
    while (scanf("%u", &seed) == 1)
    {
        setSeed(seed);
        for (int i=0; i<5; i++)
        {
            printf("The %d random number is:%u\n", i, random());
        }
        printf("Enter the 'q' to quit \n");
    }
    printf("The done~");
    return 0;
}