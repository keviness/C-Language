/*** Chapter17 example2 list.h ***/
#ifndef EXAMPLE2_LIST_H_
#define EXAMPLE2_LIST_H_
#include <stdlib.h>
#define TITLE 30

typedef struct  film
{
    char title[TITLE];
    int rate;
}Item;

typedef struct node
{
    Item item;
    struct node *next;
}Node;

typedef Node * List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);

void Travels(const List *plist, void(*pfun)(Item Item));

void EmptyTheList(List *plist);


#endif