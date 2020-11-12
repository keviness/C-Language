/*** Chapter16: example3 function ***/
#include "exercise3.h"
#include <math.h>

Cartesian polarToCartesian(Polar *ptr)
{
    Cartesian result;
    result.x = (ptr->magnitude) * sin(ptr->angle);
    result.y = (ptr->magnitude) * cos(ptr->angle);

    return result;
}