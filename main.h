#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_i(va_list l, flags_t *f);
void print_num(int n);
int print_unt(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex_low(va_list l, flags_t *f);
int print_hex_upp(va_list l, flags_t *f);
int print_bnr(va_list l, flags_t *f);
int print_oct(va_list l, flags_t *f);

/* converter */
char *num_2_string(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print_out(char s))(va_list, flags_t *);

/* get_flag */
int flag(char s, flags_t *f);

/* print_alpha */
int print_s(va_list l, flags_t *f);
int print_c(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_S(va_list l, flags_t *f);

/* print_address */
int print_add(va_list l, flags_t *f);

/* print_percent */
int print_prg(va_list l, flags_t *f);

#endif
