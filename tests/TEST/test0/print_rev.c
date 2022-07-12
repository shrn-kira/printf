#include "main.h"

/**
 * print_rev - writes the str in reverse
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_rev(va_list args, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	int j = 0;
	char c[] = "(llun)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; c[i]; i++)
			ibuf = handle_buffer(buf, c[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		ibuf = handle_buffer(buf, str[j], ibuf);
	}
	return (i);
}
