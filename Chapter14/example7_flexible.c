/*** flexible member ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flex{
    size_t count;
    double average;
    double scores[];
};

void showmember(const struct flex *pst);

int main(void)
{
    int num = 10;
    double total = 0;
    struct flex * pst1, * pst2;
    pst1->count = num;
    pst1 = malloc(sizeof(struct flex) + num*sizeof(double));
    for (int i=0; i<num; i++)
    {
        pst1->scores[i] = 20.0 - i;
        total += pst1->scores[i];
    }
    pst1->average = total/num;
    showmember(pst1);

    num = 9;
    total = 0;
    pst2->count = num;
    pst2 = malloc(sizeof(struct flex) + num*sizeof(double));
    for (int i=0; i<num; i++)
    {
        pst2->scores[i] = 20.0 - i/2;
        total += pst2->scores[i]; 
    }
    pst2->average = total/num;
    showmember(pst2);

    return 0;
}
void showmember(const struct flex *pst)
{
    puts("The informations of members:");
    for (int i=0; i<pst->count; i++)
    {
        printf("%g ", pst->scores);
    }
    printf("The average:%g", pst->average);
}