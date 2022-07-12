#include "main.h"
#include <stdio.h>
/**
 * print_p - prints the address of an input variable
 * @args: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int print_p(va_list args, char *buf, unsigned int ibuf)
{
	void *address;
	long int input;
	int i, count, digit1, isneg;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	address = (va_arg(args, void *));
	if (address == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handle_buffer(buf, nill[i], ibuf);
		return (5);
	}
	input = (intptr_t)address;
	isneg = 0;
	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = binary_array(binary, input, isneg, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	ibuf = handle_buffer(buf, '0', ibuf);
	ibuf = handle_buffer(buf, 'x', ibuf);
	for (digit1 = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && digit1 == 0)
			digit1 = 1;
		if (digit1)
		{
			ibuf = handle_buffer(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}
