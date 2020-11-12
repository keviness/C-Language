/*** Chapter17 example2 list.h ***/
#ifndef _EXAMPLE2_LIST_H_
#define _EXAMPLE2_LIST_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define TITLE 30

struct  film
{
    char title[TITLE];
    int rate;
};
typedef struct film Item;

struct node
{
    Item item;
    struct node *next;
};
typedef struct node Node;

typedef Node * List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);

void Travels(const List *plist, void(*pfun)(Item Item));

void EmptyTheList(List *plist);


#endif