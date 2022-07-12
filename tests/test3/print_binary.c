#include "main.h"
#include <stdlib.h>

/**
 * print_binary - converts a number into binary
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int), i = 0, j = 0, a = num;
	char *s;

	if (!num)
	{
		_putchar('0');
		return (1);
	}
	while (a != 0)
	{
		a /= 2;
		j++;
	}
	s = malloc(sizeof(char) * j + 1);
	if (s == NULL)
		return (-1);

	while (num > 0)
	{
		if (num % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		num /= 2;
		i++;
	}
	s[i] = '\0';
	j = 0;
	while (i != 0)
	{
		i--;
		_putchar(s[i]);
		j++;
	}
	free(s);
	return (j);
}
