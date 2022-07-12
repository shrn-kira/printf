#include "main.h"

/**
 * binary_array - prints decimal in binary
 * @bnr: pointer to binary
 * @n: input number
 * @isneg: if input number is negative
 * @size: size of the binary
 * Return: number of chars printed.
 */
char *binary_array(char *bnr, long int n, int isneg, int size)
{
	int i;

	for (i = 0; i < size; i++)
		bnr[i] = '0';
	bnr[size] = '\0';
	for (i = size - 1; n > 1; i--)
	{
		if (n == 2)
			bnr[i] = '0';
		else
			bnr[i] = (n % 2) + '0';
		n /= 2;
	}
	if (n != 0)
		bnr[i] = '1';
	if (isneg)
	{
		for (i = 0; bnr[i]; i++)
			if (bnr[i] == '0')
				bnr[i] = '1';
			else
				bnr[i] = '0';
	}
	return (bnr);
}

/**
 * print_b - converts an unsigned int argument to binary
 * @args: input string
 * @ptr: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_b(va_list args, char *ptr, unsigned int ibuf)
{
	int input, result, i, first_one, isneg;
	char *b;

	input = va_arg(args, int);
	isneg = 0;
	if (input == 0)
	{
		ibuf = handle_buffer(ptr, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}
	b = malloc(sizeof(char) * (32 + 1));
	b = binary_array(b, input, isneg, 32);
	first_one = 0;
	for (result = i = 0; b[i]; i++)
	{
		if (first_one == 0 && b[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			ibuf = handle_buffer(ptr, b[i], ibuf);
			result++;
		}
	}
	free(b);
	return (result);
}
