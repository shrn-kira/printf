#include "main.h"

/**
 * print_rot13 - writes the str in ROT13
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */

int print_rot13(va_list args, char *buf, unsigned int ibuf)
{
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char c[] = "(avyy)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; c[i]; i++)
			ibuf = handle_buffer(buf, c[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				k = 1;
				ibuf = handle_buffer(buf, rot[j], ibuf);
				break;
			}
		}
		if (k == 0)
			ibuf = handle_buffer(buf, str[i], ibuf);
	}
	return (i);
}
