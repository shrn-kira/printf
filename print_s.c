#include "main.h"

/**
 * print_s - writes the string to stdout
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */
int print_s(va_list args, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	char c[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; c[i]; i++)
			ibuf = handle_buffer(buf, c[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		ibuf = handle_buffer(buf, str[i], ibuf);
	return (i);
}
