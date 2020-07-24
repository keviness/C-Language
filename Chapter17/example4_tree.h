/*** Chapter17: example4 tree ***/
#ifndef _EXAMPLE4_TREE_H_
#define _EXAMPLE4_TREE_H_
#include <stdio.h>
#define NAME 20
#define MAXSIZE 20
typedef struct  pet
{
    char petname[NAME];
    char petkind[NAME];
}Item;

typedef struct node
{
    Item item;
    struct node *left;
    struct node *right;
}Node;

typedef struct tree
{
    Node *root;
    int size;
}Tree;

void InitializeTree(Tree *ptree);

bool TreeIsEmpty(const Tree *ptree);

bool TreeIsFull(const Tree *ptree);

int TreeNodeCount(const Tree *ptree);

bool InTree(const Item *pitem, const Tree *ptree);

bool AddItem(const Item *pitem, Tree *ptree);

bool DeleteItem(const Item *pitem, Tree *ptree);

void Travers(const Tree *ptree, void (*pfun)(Item item));

void DeleteAll(Tree *ptree);

#endif
