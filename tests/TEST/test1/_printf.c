#include "main.h"

/**
* _printf - function that produces output according to a format
* @format: character string
*
* Return: num of characters printed ecluding \0 at end of string
*/
int _printf(const char *format, ...)
{
	print_f print[] = {
		{"%b", print_binary},
		{NULL, NULL}
	};

	int count = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	va_start(args, format);
	count = get_func(format, print, args);
	va_end(args);

	return (count);
}
