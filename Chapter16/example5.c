/*** example16.12 predefined macro ***/
#include <stdio.h>
#include <string.h>

void test(void);

int main(void)
{
    puts("The information of this program:");
    printf("The Date: %s \n", __DATE__);
    printf("The Time: %s \n", __TIME__);
    printf("The standard version: %ld \n", __STDC_VERSION__);
    printf("The Name of the file: %s \n", __FILE__);
    printf("The name of the function: %s \n", __func__);
    printf("The Line code: %d \n", __LINE__);
    test();

    return 0;
}

void test(void)
{
    printf("The line: %d", __LINE__);
}