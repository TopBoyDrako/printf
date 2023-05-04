#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 */
int get_precision(const char *format, int *i, va_list list)
{

	int p = *i + 1;
	int precise = -1;

	if (format[p] != '.')
		return (precise);

	precise = 0;

	for (p += 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			precise *= 10;
			precise += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = p - 1;

	return (precise);
}
