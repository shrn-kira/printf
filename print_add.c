#include "main.h"

/**
 * print_add - prints address of input in hexa format
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_add(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = num_2_string(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
