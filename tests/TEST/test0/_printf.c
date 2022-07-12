#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, j = 0, n = 0;
	va_list args;
	int (*func)(va_list, char *, unsigned int);
	char *buffer;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, n), free(buffer), va_end(args);
				return (-1);
			}
			else
			{	func = get_print_func(format, i + 1);
				if (func == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], n), j++, i--;
				}
				else
				{
					j += func(args, buffer, n);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], n), j++;
		for (n = j; n > 1024; n -= 1024)
			;
	}
	print_buf(buffer, n), free(buffer), va_end(args);
	return (j);
}
