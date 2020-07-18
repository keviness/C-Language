/*** Chapter17: example3 queue ***/
#ifndef _EXAMPLE3_QUEUE_H_
#define _EXAMPLE3_QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 15
typedef int Item;

typedef struct node 
{
    Item item;
    struct node *next;
}Node;

typedef struct queue
{
    Node *head;
    Node *tail;
    Item counts;
}Queue;

void InitializeQueue(Queue *pqueue);

bool QueueIsFull(const Queue *pqueue);

bool QueueIsEmpty(const Queue *pqueue);

unsigned int QueueItemCount(const Queue *pqueue);

bool AddItem(Item item, Queue *pqueue);

bool ShitItem(Item *pitem, Queue *pqueue);

void EmptyQueue(Queue *pqueue);

#endif