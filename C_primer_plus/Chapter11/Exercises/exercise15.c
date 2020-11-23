#include <stdio.h>
#include <ctype.h>

int my_atoi(char *string);

int main(int argc, char *argv[])
{
	// driver for my_atoi()

	int input;

	if (argc != 2)
		puts("Usage: <program_name> <arg_1>");
	else
	{
		input = my_atoi(argv[1]);
		printf("%d + 5 = %d\n", input, input + 5);
		printf("%d / 2 = %d\n", input, input / 2);
		printf("%d %% 3 = %d\n", input, input % 3);
	}

	return 0;
}

int my_atoi(char *string)
{
	// convert string to integer
	// returns 0 on error

	int sum = 0;

	while (*string != '\0')
	{
		if (!isdigit(*string))
			// string is not a pure integer -- return 0
			return 0;
		else
		{
			 sum = 10 * sum + (*string - '0'); // add newest digit in ones place
		}

		string++;
	}

	return sum;
}