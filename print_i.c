#include "main.h"

/**
* print_i - prints an integer
* @args: input string
* @ibuf: index for buff pointer
* @buf: buff pointer
* Return: the decimal function
*/
int print_i(va_list args, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int int_in, temp, i, div, isneg;

	input = va_arg(args, int);
	isneg = 0;
	if (input < 0)
	{
		int_in = input * -1;
		ibuf = handle_buffer(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = input;
	}

	temp = int_in;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handle_buffer(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

/**
* printint - prints integer with a plus symbol
* @args: input string
* @ibuf: index for buff pointer
* @buf: buff pointer
* Return: counter
*/
int printint(va_list args, char *buf, unsigned int ibuf)
{
	unsigned int int_in, temp, i, div;
	int input;

	input = va_arg(args, int);
	if (input < 0)
	{
		int_in = input * -1;
		ibuf = handle_buffer(buf, '-', ibuf);
	}
	else
	{
		int_in = input;
		ibuf = handle_buffer(buf, '+', ibuf);
	}
	temp = int_in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handle_buffer(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}
