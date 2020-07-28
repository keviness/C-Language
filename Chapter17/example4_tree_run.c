/*** Chapter17 example4: tree ***/
#include <stdio.h>
#include <stdlib.h>
#include "example4_tree.h"

char menu(void);
void addPet(Tree *ptree);
void deletePet(Tree *ptree);
void showPet(const Tree *ptree);
void findPet(const Tree *ptree);
void upperCase(char *str);
char *s_gets(char *str, int num);

int main(void)
{
    Tree pets;
    char choice;
    InitializeTree(&pets);

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a': addPet(&pets);
            break;
        case 'l': showPet(&pets);
            break;
        case 'f': findPet(&pets);
            break;
        case 'n': printf("There are %d pets\n", TreeNodeCount(&pets));
            break;
        case 'd': deletePet(&pets);
            break;
        default: puts("switch error!");
        }
    }
    ClearTree(&pets);
    puts("The done~");

    return 0;
}

char menu(void)
{
    char ch;
    puts("Enter the letter corresponding your choice:");
    puts("a)add a pet         l)show list of pets");
    puts("n)number of pets    f)find pets");
    puts("d)delete a pet      q)quit");
    while ((ch = getchar()) != '\n')
    {
        while (getchar() != '\n')
            continue;
        if (strchr("alnfdq", ch) == NULL)
        {
            puts("The choice you input error! try again:");
        }
        else
        {
            break;
        }
    }
    if (ch == '\n')
        ch = 'q';
    return ch;
}

void addPet(Tree *pets)
{
    Item temp;
    if (TreeIsFull(pets))
    {
        puts("The pets room is full!");
    }
    else
    {
        puts("Enter the pet name:");
        s_gets(temp.petname, NAME);
        puts("Enter the pet kind:");
        s_gets(temp.petkind, NAME);
        upperCase(temp.petkind);
        upperCase(temp.petname);
        if (AddItem(&temp, pets))
            puts("Add item successfully!");
        else
        {
            puts("Add item failurely!");
        }
    }
}

void deletePet(Tree *pets)
{
    Item temp;
    if (TreeIsEmpty(pets))
    {
        puts("The tree is empty!");
    }
    else
    {
        puts("Enter the pet kind:");
        s_gets(temp.petkind, NAME);
        puts("Enter the pet name:");
        s_gets(temp.petname, NAME);
        upperCase(temp.petkind);
        upperCase(temp.petname);
        if (DeleteItem(&temp, pets))
        {
            puts("Delete the item successfully!");
        }
        else
        {
            puts("The item is not exit!");
        }
    }
}

void findPet(const Tree *pets)
{
    Item temp;
    if (TreeIsEmpty(pets))
    {
        puts("The pets room is empty!");
    }
    else
    {
        puts("Enter the pet kind:");
        s_gets(temp.petkind, NAME);
        puts("Enter the pet name:");
        s_gets(temp.petname, NAME);
        upperCase(temp.petkind);
        upperCase(temp.petname);
        if (IsInTree(&temp, pets))
        {
            puts("The item is exit");
        }
        else
        {
            puts("The item is not exitting in the pets room");
        }
    }
}

void upperCase(char *str)
{
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}

void showPet(const Tree *pets)
{
    if (TreeIsEmpty(pets))
    {
        puts("The pets room is empty!");
    }
    else
    {
        Travers(pets, printItem);
    }
    
}

void printItem(Item item)
{
    printf("The pet name:%s, The pet kind:%s\n", item.petname, item.petkind);
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
        if (*str == '\n')
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