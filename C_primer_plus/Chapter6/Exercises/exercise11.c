#include <stdio.h>

int main(void)
{
	int int_array[8];
	int i; // array index

	printf("Enter 8 integers:\n");
	for (i = 0; i < 8; i++) // read ints into array
	{
		scanf("%d", &int_array[i]);
	}
	for (i--; i >= 0; i--) // decrement i to 7 to initialize loop
	{
		printf("%d", int_array[i]);
	}
	printf("\n");

	return 0;
}