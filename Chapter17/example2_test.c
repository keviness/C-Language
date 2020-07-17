/*** Chapter17: example2 test.c ***/
#include <stdio.h>
#include "example2_list.h"

char *s_gets(char *str, int num);
void show_item(Item item);

int main(void)
{
    List movie;
    Item temp;

    InitializeList(&movie);
    if (ListIsFull(&movie))
    {
        puts("Can\'t get memory!");
        exit(EXIT_SUCCESS);
    }
    puts("Enter the book title:");
    while (s_gets(temp.title, TITLE) && temp.title[0]!='\0')
    {
        puts("Enter the rate:");
        scanf("%d", &temp.rate);
        while (getchar() != '\n') continue;
        if (!AddItem(temp, &movie))
        {
            puts("Can\'t add the item.");
            break;
        }
        if (ListIsFull(&movie))
        {
            puts("The list is Full.");
            break;
        }
        puts("Enter the next book title.");
    }
    if (ListIsEmpty(&movie))
    {
        puts("The list is empty!");
    }
    else
    {
        puts("The content of the list:");
        Travels(&movie, show_item);
    }

    printf("The list item count:\n", ListItemCount(&movie));

    EmptyTheList(&movie);
    puts("The Done~");
    return 0;
}

void show_item(Item item)
{
    printf("The book title:%s\n", item.title);
    printf("The book rate:%d\n", item.rate);
}

char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\n' && *str!='\0')
        {
            str++;
        }
        if (*str != '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ptr;
}