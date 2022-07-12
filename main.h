#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int (*get_func(const char *s, int index))(va_list, char *, unsigned int);
int print_s(va_list args, char *buf, unsigned int ibuf);
int print_c(va_list arguments, char *buf, unsigned int ibuf);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_buffer(char *buf, unsigned int nbuf);
char *binary_array(char *bnr, long int n, int isneg, int size);
int ev_print(const char *s, int index);
int printi(va_list args, char *buf, unsigned int ibuf);
int print_i(va_list args, char *buf, unsigned int ibuf);
unsigned int handle_buffer(char *buf, char c, unsigned int ibuf);
int print_b(va_list args, char *ptr, unsigned int ibuf);

#endif
