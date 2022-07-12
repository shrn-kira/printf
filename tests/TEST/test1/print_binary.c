#include "main.h"

/**
* print_binary - converts a number into binary
* @args: list of arguments
* @s: string to be converted
*
* Return: amount of chars printed
*/
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s


	if (!n)
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
	
	while (n > 0)
	{
		if (n % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		n /= 2;
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
