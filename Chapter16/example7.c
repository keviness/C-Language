/*** example16.15: generic choose function ***/
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4*atan(1)))
#define SQART(X) __Generic((X),\
    long double: sqrtl,\
    float: sqrtf,\
    default: sqrt\
)(X)

#define SIN(X) __Generic((X),\
    long double: sinl((X)/RAD_TO_DEG),\
    float: sinf((X)/RAD_TO_DEG),\
    default: sin((X)/RAD_TO_DEG)\
)

int main(void)
{
    float x = 45.0F;
    long double xx = 45.00L;
    double xxx =  45.0;
    float y;
    long double yy;
    double yyy;

    y = SQART(x);
    yy = SQART(xx);
    yyy = SQART(xxx);

    printf("y:%f \n", y);
    printf("yy:%lf \n", yy);
    printf("yyy:%g \n", yyy);
    printf("yy in sin: %lf \n", SIN(xx));
    printf("yyy in sin: %g \n", SIN(xxx));
    printf("y in sin: %f \n", SIN(x));

    return 0;
}