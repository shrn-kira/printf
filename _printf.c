#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: num of characters printed ecluding \0 at end of string
 * */
int _printf(const char *format, ...)
{
	va_list args;
	int output;

	va_start (args, format);
	output = vprintf (stdout, format, args);
	va_end (args);

	return (output)
}

