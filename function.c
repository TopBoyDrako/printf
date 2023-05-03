#include "main.h"

/**
 * print_char - This prints a char
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Gets active flags
 * @width: Width
 * @precision: Get Precision
 * @size: Get Size 
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - function to Print string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: get Precision 
 * @size: Size
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = 0, i;
	char *al = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (al == NULL)
	{
		al = "(null)";
		if (precision >= 6)
			al = "      ";
	}

	while (al[l] != '\0')
		l++;

	if (precision >= 0 && precision < l)
		l = precision;

	if (width > l)
	{
		if (flags & F_MINUS)
		{
			write(1, &al[0], l);
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(types);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width:  width.
 * @precision: Precision 
 * @size: Size 
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int p = BUFF_SIZE - 2;
	int m = 0;
	long int l = va_arg(types, long int);
	unsigned long int ai;

	l = convert_size_number(l, size);

	if (l == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	ai = (unsigned long int)l;

	if (l < 0)
	{
		ai = (unsigned long int)((-1) * l);
		m = 1;
	}

	while (ai > 0)
	{
		buffer[p--] = (ai % 10) + '0';
		ai /= 10;
	}

	p++;

	return (write_number(ai, p, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

