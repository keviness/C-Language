/*** test name.h file ***/
#include "name.h"
#include "name.h"
int main(void)
{
    names students = {
        "Nancy",
        "lake"
    };
    names childrens[SIZE] = {
        {"kevin", "lake"},
        {"nancy", "lake"},
        {"john", "bob"}
    };
    names group;

    puts("The inforations:");
    printf("The first name: %s \n", students.first_name);
    printf("The last name: %s \n", students.last_name);
    puts("**************************");

    puts("The informations:");
    for (int i=0; i<3; i++)
    {
        printf("The %d children: \n", i+1);
        printf("The first name:%s \n", childrens[i].first_name);
        printf("The last name:%s \n", childrens[i].last_name);
        puts("***********");
    }
    
    /*
    puts("**************************");
    get_name(&group);
    puts("The information of the groups:");
    printf("The first name: %s \n", group.first_name);
    printf("The last name: %s \n", group.last_name);
    */

    return 0;
}