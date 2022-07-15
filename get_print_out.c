#include "main.h"

/**
 * get_print_out - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print_out(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_i},
		{'s', print_s},
		{'c', print_c},
		{'d', print_i},
		{'u', print_unt},
		{'x', print_hex_low},
		{'X', print_hex_upp},
		{'b', print_bnr},
		{'o', print_oct},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_S},
		{'p', print_add},
		{'%', print_prg}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
