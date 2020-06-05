/*** Chapter16 exercise3 ***/
#ifndef __EXERCISE3_H__
#define __EXERCISE3_H__
#include <stdio.h>

typedef struct polar
{
    double angle;
    double magnitude;
}Polar;

typedef struct cartesian
{
    double x;
    double y;
}Cartesian;

Cartesian polarToCartesian(Polar *);
#endif