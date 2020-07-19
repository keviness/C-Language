/*** Chapter17: example3 queue ***/
#include "example3_queue.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Queue line;
    Item temp;
    char choice;
    puts("Enter the choice:");
    InitializeQueue(&line);
    while ((choice = getchar()) != 'q')
    {
        if (choice!='a' && choice!='d')
            continue;
        if (choice == 'a')
        {
            puts("Enter the item:");
            scanf("%ld", &temp);
            while (getchar() != '\n') continue;
            if (!QueueIsFull)
            {
                printf("The %ld putting in the queue.\n", temp);
                AddItem(temp, &line);
            }
            else
            {
                puts("The queue is full!");
            }
        }
        else
        {
            if (QueueIsEmpty(&line))
            {
                puts("The queue is empty! no item can be deleted!");
            }
            else
            {
                ShitItem(&temp, &line);
                printf("removing the %ld item from queue.\n", temp);
            }
        }
    }
    printf("There are %d items in the queue.\n", line.counts);
    puts("The Done~");

    return 0;   
}