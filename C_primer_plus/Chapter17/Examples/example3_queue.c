/*** Chapter17: example3 queue ***/
#include <stdio.h>
#include "example3_queue.h"

static void CopyToNode(Item item, Node *pnew);
static void CopyToItem(Node *pnew, Item *pitem);

void InitializeQueue(Queue *pqueue)
{
    pqueue->head = NULL;
    pqueue->tail = NULL;
    pqueue->counts = 0;
}

bool QueueIsFull(const Queue *pqueue)
{
    return pqueue->counts == MAXSIZE;
}

bool QueueIsEmpty(const Queue *pqueue)
{
    return pqueue->counts == 0;
}

unsigned int QueueItemCount(const Queue *pqueue)
{
    return pqueue->counts;
}

bool AddItem(Item item, Queue *pqueue)
{
    Node *pnew;
    if (QueueIsFull(pqueue))
    {
        puts("The queue is empty!");
        return false;
    }
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        puts("Can\'t locate the memory!");
        exit(EXIT_FAILURE);
    }
    pnew->next = NULL;
    CopyToNode(item, pnew);
    if (QueueIsEmpty(pqueue))
    {
        pqueue->head = pnew;
    }
    else
    {
        pqueue->tail->next = pnew;
    }
    pqueue->tail = pnew;
    pqueue->counts++;
    if (pqueue->counts == 0)
    {
        pqueue->tail = NULL;
    }

    return true;
}

bool ShitItem(Item *pitem, Queue *pqueue)
{
    Node *save;
    if (QueueIsEmpty(pqueue))
    {
        puts("The queue is empty!");
        return false;
    }
    CopyToItem(pqueue->head, pitem);
    save = pqueue->head;
    pqueue->head = pqueue->head->next;
    free(save);
    pqueue->counts--;
    if (pqueue->counts == 0)
    {
        pqueue->tail = NULL;
    }

    return true;
}

void EmptyQueue(Queue *pqueue)
{
    Item temp;
    while (!QueueIsEmpty(pqueue))
    {
        ShitItem(&temp, pqueue);
    }
}

static void CopyToNode(Item item, Node *pnew)
{
    pnew->item = item;
}

static void CopyToItem(Node *pqueue, Item *pitem)
{
    *pitem = pqueue->item;
}