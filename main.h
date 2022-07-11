#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>

/**
 * struct print - main structure taht takes a character and a function
 * @valid: way to compare the function
 * @f: pointer to function
 *
 * Description: struct that stores pointers to a printer functions
 */
typedef struct specifier
{
	char *valid;
	int(*f)(va_list);

} spec;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int _putchar(char c);
int print_b(va_list args);
int print_percent(va_list args);
int (*get_func(char x))(va_list args);

#endif
