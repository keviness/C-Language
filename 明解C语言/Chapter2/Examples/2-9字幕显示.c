/*** example2-9:字幕显示 ***/
#include <stdio.h>
#include <time.h>
#include <string.h>

int sleep(unsigned int mins);

int main(void)
{
    char *str = "keviness ";
    int length = strlen(str);
    int count = 0;
    while (1)
    {
        putchar('\r');
        for (int i=0; i<length; i++)
        {
            if (count+i < length)
            {
                putchar(str[count+i]);
            }
            else
            {
                putchar(str[count+i-length]);
            }
            
        }
      
        fflush(stdout);
        sleep(500);
        /*
        //right->left
        if (count < length-1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        */
        //left->right
        if (count > 0)
        {
            count--;
        }
        else
        {
            count = length-1;
        }
        
    }
    
    return 0;
}

int sleep(unsigned int mins)
{
    clock_t clock1=clock(), clock2;

    do
    {
        if ((clock2=clock()) == (clock_t)-1)
        {
            return 0;
        }
    }while ((clock2-clock1)*1000.0/CLOCKS_PER_SEC < mins);
    return 1;
}