#include <stdio.h>
#include <string.h>
#define SIZE 20
struct names
{
    char first_name[SIZE];
    char last_name[SIZE];
};

struct friends
{
    struct names handle;
    char job[SIZE];
    char favorite_book[SIZE];
    float income;
};

int main(void)
{
    struct friends guys[2] = {
        {
            {"lake", "keviness"},
            "programmer",
            "protect the kingdown",
            1234.56
        },
        {
            {"Nancy", "Bob"},
            "teacher",
            "my fighting",
            12456.56
        }
    };
    struct friends * him;
    him = &guys[0];
    puts("The address of the struct type:");
    printf("addess #1: %p   address #2: %p \n", &guys[0], &guys[1]);
    puts("The address of the pointer:");
    printf("pointer #1: %p    pointer #2:%p \n", him, him+1);
    puts("**********");
    printf("The name:%s \n", him->handle.first_name);
    printf("The him->job:%s   The guys[0].job:%s \n", him->job, (*him).job);
    printf("The him->favorite book:%s   The guys[0].job:%s \n", him->favorite_book, guys[0].favorite_book);
    puts("**********");
    him++;
    printf("The name:%s \n", him->handle.first_name);
    printf("The him->job:%s   The guys[1].job:%s \n", him->job, (*him).job);
    printf("The him->favorite book:%s   The guys[1].job:%s \n", him->favorite_book, guys[1].favorite_book);
    return 0;

}

