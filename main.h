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
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);
int ev_print_func(const char *s, int index);
int print_buffer(char *buf, unsigned int nbuf);
char *binary_array(char *bnr, long int n, int isneg, int size);
int ev_print(const char *s, int index);
int printi(va_list args, char *buf, unsigned int ibuf);
int print_i(va_list args, char *buf, unsigned int ibuf);
unsigned int handle_buffer(char *buf, char c, unsigned int ibuf);
int print_b(va_list args, char *ptr, unsigned int ibuf);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_oct_array(char *bnr, char *oct);
int print_hex(va_list args, char *buf, unsigned int ibuf);
int print_upx(va_list args, char *buf, unsigned int ibuf);
int print_oct(va_list args, char *buf, unsigned int ibuf);
int print_unt(va_list args, char *buf, unsigned int ibuf);
int print_S(va_list args, char *buf, unsigned int ibuf);
int print_p(va_list args, char *buf, unsigned int ibuf);
int print_rev(va_list args, char *buf, unsigned int ibuf);
int print_rot13(va_list args, char *buf, unsigned int ibuf);
int print_a(va_list args, char *buf, unsigned int ibuf);
int print_lo_hex(va_list args, char *buf, unsigned int ibuf);
int print_lo_i(va_list args, char *buf, unsigned int ibuf);
int print_lo_oct(va_list args, char *buf, unsigned int ibuf);
int print_lo_uint(va_list args, char *buf, unsigned int ibuf);
int print_lo_upx(va_list args, char *buf, unsigned int ibuf);


#endif
