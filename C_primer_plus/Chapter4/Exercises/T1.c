#include <stdio.h>
int main(void)
{
    char fir_name[10], las_name[10];
    printf("Enter your name(first last):");
    scanf("%s, %s", fir_name, las_name);

    printf("%s,%s\n", fir_name, las_name);
    printf("%5s,%-5s", fir_name, las_name);

    return 0;
}