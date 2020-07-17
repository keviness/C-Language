#include <stdio.h>
#include <stdlib.h>

#include "example2_list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist)
{
    *plist = NULL;
}

bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    return false;
}

bool ListIsFull(const List *plist)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
        free(temp);
        return true;
    free(temp);
    return false;
}

unsigned int ListItemCount(const List *plist)
{
    unsigned int item_count = 0;
    Node *scan = *plist;
    while (scan != NULL)
    {
        item_count++;
        scan = scan->next;
    }
    return item_count;
}

bool AddItem(Item item, List *plist)
{
    Node *pnew;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        printf("Can\'t add item\n");
        return false;
    }
    CopyToNode(item, pnew);
    Node *scan = *plist;
    if (scan == NULL)
    {
        (*plist)->item = item;
    }
    else
    {
        while (scan->next != NULL)
        {
            scan = scan->next;
        }
        scan->item = item;
    }
    return true;
}

void Travels(const List *plist, void(*pfun)(Item Item))
{
    Node *pnode = *plist;
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist)
{
    Node *save ;
    while (*plist != NULL)
    {
        save = (*plist)->next;
        free(*plist);
        *plist = save;
    }
}

static void CopyToNode(Item item, Node *pnew)
{
    pnew->item = item;
}