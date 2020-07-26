/*** Chapter17: tree ***/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "example4_tree.h"

typedef struct pair
{
    Node *parent;
    Node *child;
}Pair;

static Node *MakeNode(const Item *pitem);
static bool ToLeft(const Item *item1, const Item *item2);
static bool ToRight(const Item *item1, const Item *item2);
static void AddNodeInTree(Node *pNew, Node *proot);
static void InOrder(const Node *proot, void(*pfun)(Item item));
static Pair SeekNode(const Item *pitem, const Tree *ptree);
static void DeleteNodeInTree(Node **proot);
static void DeleteAllNodes(Node *proot);

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
    return ptree->size;
}

bool InTree(const Item *pitem, const Tree *ptree)
{
    return (SeekNode(pitem, ptree).child==NULL)? false:true;
}

bool AddItem(const Item *pitem, Tree *ptree)
{
    Node *newNode;
    if (TreeIsFull)
    {
        fprintf(stderr, "The Tree is full!\n");
        return false;
    }
    if (!IsInTree)
    {
        fprintf(stderr, "Attempted to add the duplicate item.\n");
        return false;
    }
    newNode = MakeNode(pitem);
    if (newNode == NULL)
    {
        fprintf(stderr, "Can\'t locate the memory!\n");
        return false;
    }

    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = newNode;
    else
    {
        AddNodeInTree(newNode, ptree);
    }

    return true;
}

bool DeleteItem(const Item *pitem, Tree *ptree)
{
    Pair look;
    look = SeekNode(pitem, ptree);
    if (look.child == NULL)
    {
        fprintf(stderr, "Can\'t seek the item node");
        return false;
    }

    if (look.parent == NULL)
    {
        DeleteNodeInTree(&ptree->root);
    }
    else if (look.parent->left == look.child)
        DeleteNodeInTree(&look.parent->left);
    else
    {
        DeleteNodeInTree(&look.parent->right);
    }
    ptree->size--;

    return true;
}

void Traverse(const Tree *ptree, void(*pfun)(Item item))
{
    if (ptree == NULL)
        InOrder(ptree->root, pfun);
}

void ClearTree(Tree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

static void InOrder(const Node *proot, void(*pfun)(Item item))
{
    if (proot != NULL)
    {
        InOrder(proot->left, pfun);
        (*pfun)(proot->item);
        InOrder(proot->right, pfun);
    }
}

static void DeleteAllNodes(Node *proot)
{
    Node *pright;
    if (proot != NULL)
    {
        pright = proot->right;
        DeleteAllNodes(proot->left);
        free(proot);
        DeleteAllNodes(pright);
    }
}

static bool ToLeft(const Item *pitem1, const Item *pitem2)
{
    int compare;
    if ((compare = strcmp(pitem1->petkind, pitem2->petkind)) < 0)
    {
        return true;
    }
    else if (compare==0 && strcmp(pitem1->petname, pitem2->petname)<0)
        return true;
    else
    {
        return false;
    }
}

static bool ToRight(const Item *pitem1, const Item *pitem2)
{
    int compare;
    if ((compare = strcmp(pitem1->petkind, pitem2->petkind)) > 0)
        return true;
    else if (compare==0 && strcmp(pitem1->petname, pitem2->petname)>0)
        return true;
    else
    {
        return false;
    }
}

static void AddNodeInTree(Node *pnewNode, Node *proot)
{
    if (ToLeft(&pnewNode->item, &proot->item))
    {
        if (proot->left == NULL)
            proot->left = pnewNode;
        else
            AddNodeInTree(pnewNode, proot->left);
    }
    else if (ToRight(&pnewNode->item, &proot->item))
    {
        if (proot->right == NULL)
            proot->right = pnewNode;
        else
            AddNodeInTree(pnewNode, proot->right);
    }
    else
    {
        fprintf(stderr, "Location error in AddNodeInTree()\n");
        exit(EXIT_FAILURE);
    }
}

static Node *MakeNode(const Item *pitem)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->item = *pitem;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

static Pair SeekItem(const Item *pitem, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
    {
        fprintf(stderr, "The tree is empty!\n");
        exit(EXIT_FAILURE);
    }

    while (look.child != NULL)
    {
        if (ToLeft(pitem, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pitem, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
        {
            break;
        }
    }
    return look;
}

static void DeleteNodeInTree(const Node **pnode)
{
    Node *temp;
    if ((*pnode)->left == NULL)
    {
        temp = *pnode;
        (*pnode) = (*pnode)->right;
        free(temp);
    }
    else if ((*pnode)->right == NULL)
    {
        temp = *pnode;
        (*pnode) = (*pnode)->left;
        free(temp);
    }
    else
    {
        for (temp = (*pnode)->left; temp->right!=NULL; temp=temp->right)
            continue;
        temp->right = (*pnode)->right;
        temp = *pnode;
        *pnode = (*pnode)->left;
        free(temp);
    }
}