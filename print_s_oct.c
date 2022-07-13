#include "main.h"

/**
* print_s_oct - prints long decimal number in octal
* @args: input number
* @buf: buff pointer
* @ibuf: index for buff pointer
*
* Return: number of chars printed.
*/
int print_s_oct(va_list args, char *buf, unsigned int ibuf)
{
	short int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(args, int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = handle_buffer(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (16 + 1));
	binary = binary_array(binary, int_input, isnegative, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = fill_short_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handle_buffer(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
