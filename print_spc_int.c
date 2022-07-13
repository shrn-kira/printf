#include "main.h"

/**
* print_spc_int - prints int begining with space
* @args: input string
* @buf: buff pointer
* @ibuf: index for buff pointer
*
* Return: number of chars printed
*/
int print_spc_int(va_list args, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(args, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handle_buffer(buf, '-', ibuf);
	}
	else
	{
		int_in = int_input;
		ibuf = handle_buffer(buf, ' ', ibuf);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handle_buffer(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}
