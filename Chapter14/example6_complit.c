/*** compound struct type ***/
#include <stdio.h>
#include <string.h>
#define TITLE 80
#define AUTHOR 80
struct book{
    char title[TITLE];
    char author[AUTHOR];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;
    puts("Enter your scores:");
    scanf("%2d", &score);

    if (score >= 85)
    {
        readfirst = (struct book){
            "crime and punishment",
            "kevin",
            67.23
            };
    }
    else
    {
        readfirst = (struct book){
            "Mr lake\'s nice hat",
            "lucy",
            89.32
        };
    }
    puts("The informations of the book:");
    printf("The title:%s \n", readfirst.title);
    printf("The author:%s \n", readfirst.author);
    printf("The value:%3.3f \n", readfirst.value);
    
    return 0;
}