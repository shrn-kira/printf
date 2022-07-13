#include "main.h"
/**
 * get_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"c", print_c}, {"s", print_s},
		{"b", print_b}, {"l", print_prg},
		{"h", print_prg}, {" %", print_prg},
		{"d", print_i}, {"i", print_i},
		{"b", print_b}, {"u", print_unt},
		{"X", print_upx}, {"S", print_S},
		{"p", print_p}, {"x", print_hex},
		{"o", print_oct}, {"r", print_rev},
		{"R", print_rot13}, {"p", print_a},
		{"lx", print_lo_hex}, {"li", print_lo_i},
		{"ld", print_lo_i}, {"#X", print_upx},
		{"lo", print_lo_oct}, {"lu", print_lo_uint},
		{"lX", print_lo_upx}, {"#x", print_n_hex},
		{"#o", print_n_oct}, {"hx", print_s_hex},
		{"hi", print_s_int}, {"hd", print_s_int},
		{"ho", print_s_oct}, {"#i", print_i},
		{"#d", print_i}, {"#u", print_unt},
		{"+i", printint}, {"+d", printint},
		{"+u", print_unt}, {"+o", print_oct},
		{"+x", print_hex}, {"+X", print_upx},
		{" u", print_unt}, {" o", print_oct},
		{" x", print_hex}, {" X", print_upx},
		{"%", print_prg}, {" +i", printint},
		{" +d", printint}, {"+ i", printint},
		{"hu", print_s_uint}, {"hX", print_s_upx},
		{" i", print_spc_int}, {" d", print_spc_int},
		{"+ d", printint}, {NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].f);
}
