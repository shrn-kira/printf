#include "main.h"

/**
*  print_unt - prints an unsigned int
*  @args: number to print
*  @buf: buff pointer
*  @ibuf: index for buff pointer
*
*  Return: number of chars printed.
*/
int print_unt(va_list args, char *buf, unsigned int ibuf)
{
	unsigned int int_in, int_temp, i, div;

	int_in = va_arg(args, unsigned int);
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
	return (i);
}

/**
*  print_oct - prints decimal number in octal
*  @args: input number
*  @buf: buff pointer
*  @ibuf: index for buff pointer
*
*  Return: number of chars printed.
*/
int print_oct(va_list args, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);
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

/**
* print_hex - prints a decimal in hexadecimal
* @args: input string
* @buf: buff pointer
* @ibuf: index for buff pointer
*
* Return: number of chars printed
*/
int print_hex(va_list args, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handle_buffer(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

/**
* prinnupx - prints number in uppercase hex
* @args: input string
* @buf: buff pointer
* @ibuf: index for buff pointer
*
* Return: number of chars printed
*/
int prinnupx(va_list args, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

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
	ibuf = handle_buffer(buf, '0', ibuf);
	ibuf = handle_buffer(buf, 'X', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handle_buffer(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}

