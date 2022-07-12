#include "main.h"

/**
* print_aux - auxiliar function of _printf
* @format: text and ways to format the output
* @print: struct of indetifiers and functions
* @args: list of arguments
*
* Return: amount of chars printed
*/
int get_func(const char *format, print_f print[], va_list args)
{
	int i = 0, j = 0, count = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (print[j].s[0])
			{
				if (print[j].s[0] == format[i + 1])
				{
					count += print[j].f(args);
					i++;
					break;
				}
				if (print[j + 1].s == NULL)
				{
					if (format[i + 1] > 32 && format[i + 1] < 127)
					{
						count++, _putchar(format[i]);
						break;
					}
					else
						return (-1);
				}
				j++;
			}
			if (format[i + 1] != '\0')
			{
				i++;
				continue;
			}
			else
				break;
		}
		_putchar(format[i]);
		count++;
		i++;
	}
	return (count);
}
