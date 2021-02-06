/*** Chapter6: list6-13~list6-15 ***/
#include <stdio.h>

//method first
/*
int main(int argc, char *argv[])
{
    for (int i=0; i<argc; i++)
    {
        printf("argv[%d]: %s \n", i, argv[i]);
    }

    return 0;
}
*/

//method second
/*
int main(int argc, char **argv)
{
    int i = 0;
    while (argc-- > 0)
    {
        printf("argv[%d]: %s  \n", i++, *argv++);
    }
    
    return 0;
}
*/

//method third

int main(int argc, char **argv)
{
    int i=0;
    while (*argv)
    {
        printf("argv[%d]: %s \n", i++, *argv++);
    }
    
    return 0;
}

//method forth
/*
int main(int argc, char **argv)
{
    int i=0;
    char ch;
    while (argc-- > 0)
    {
        printf("argv[%d]: \n", i++);
        while (ch = *(*argv)++)      //---> ch=**argv; *argv++
        {
            putchar(ch);
        }
        argv++;
        putchar('\n');
    }

    return 0;
}
*/