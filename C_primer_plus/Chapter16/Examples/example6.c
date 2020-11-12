/*** example16.14: <math.h> ***/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define RAD_TO_DEG (180 * (4*atan(1)))
typedef struct rect_input{
    double x;
    double y;
}input_value;

typedef struct polar_output{
    double magnitude;
    double angle;
}output_value;

output_value calculate(input_value);

int main(void)
{
    input_value input;
    output_value output;

    printf("Enter the x and y: \n");
    while (scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        output = calculate(input);
        puts("The result:");
        printf("The magnitude: %0.2f \n", output.magnitude);
        printf("The angle: %0.2f \n", output.angle);
    }
    puts("The Done~");
    
    return 0;
}

output_value calculate(input_value input)
{
    output_value output;
    output.magnitude = sqrt(input.x*input.x + input.y*input.y);
    if (output.magnitude == 0)
    {
        output.angle = 0.0;
    }
    else
    {
        output.angle = RAD_TO_DEG * atan2(input.x, input.y);
    }
    return output;
}