#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h> 
#include <unistd.h>

/**
 * struct print - main structure taht takes a character and a function
 * @s: way to compare the function
 * @f: pointer to function
 *
 * Description: struct that stores pointers to a printer functions
 */
typedef struct print
{
	char *s;
	int(*f)(va_list);
} print_f;

int _printf(const char *format, ...);
int _putchar(char c);
int get_func(const char *format, print_f print[], va_list args);
int print_binary(va_list args)

#endif
