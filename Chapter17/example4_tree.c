/*** Chapter17: tree ***/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "example4_tree.h"

void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if (ptree->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TreeIsFull(const Tree *ptree)
{
    if (ptree->size == MAXSIZE)
        return true;
    else
        return false;
}

int TreeNodeCount(const Tree *ptree)
{
    return ptree->size
}