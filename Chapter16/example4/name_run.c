#include "name.h"
#include <stdio.h>

int main(void)
{
    names candidate;
    get_name(&candidate);
    puts("The information of the candidates:");
    show_name(&candidate);
    puts("Done~");
    return 0;
}