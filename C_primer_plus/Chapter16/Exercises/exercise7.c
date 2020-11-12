/*** Chapter16: exercise7 ***/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main(void)
{
	double * p1;
	double * p2;
	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6, 7.8, 8.9, 9.0);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0, 12.34, 34.6); 
	show_array(p1, 5);
	show_array(p2, 4);
	free(p1);
	free(p2);

	return 0;
}

double * new_d_array(int n, ...)
{
    double *ptr;
    va_list ap;
    va_start(ap, n);

    ptr = (double *)malloc(n * sizeof(double));
    if (!ptr)
    {
        printf("Can\'t locate te memory \n");
    }
    else
    {   
        for (int i=0; i<n; i++)
        {
            ptr[i] = va_arg(ap, double);
        }
    }

    return ptr;
}

void show_array(const double arr[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("%g ", arr[i]);
    }
    putchar('\n');
}