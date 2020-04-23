/*** random io by binnary ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int main(int argc, char *argv[])
{
    FILE *pf;
    double value;
    int i = 0;
    double number[SIZE];
    long pos;

    if (argc < 2)
    {
        printf("Usage:The %s program need two arguments.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i=0; i<SIZE; i++)
    {
        number[i] = 100.0*i + 1.0/(i+1);
    }
    if ((pf = fopen(argv[1], "wb")) == NULL)
    {
        printf("Usage:The %s file can\'t open. \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (fwrite(number, sizeof(double), SIZE, pf) == 0)
    {
        printf("Usage:Error in writing in the %s file. \n", argv[1]);
    }
    if (fclose(pf) != 0)
    {
        printf("Usage:Error in closing %s file .\n", argv[1]);
    }
    if ((pf = fopen(argv[1], "rb")) == NULL)
    {
        printf("Usage:The file %s can\'t open. \n", argv[1]);
    }
    
    puts("Enter the index:");
    while (scanf("%d", &i)==1 && i>=0 && i<SIZE)
    {
        pos = (long)i * sizeof(double);
        fseek(pf, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, pf);
        printf("The random value of the index %d is: %g \n", i, value);
        puts("Enter the next index:");
    }
    if (fclose(pf) != 0)
    {
        printf("Usage:The %s file can\'t open. \n", argv[1]);
    }
    puts("The Done~");

    return 0;
}