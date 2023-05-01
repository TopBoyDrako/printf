#include "main.h"

/**
 * _printf - formatted output and print data.
 */
int _printf(const char *fmt, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, fmt), buffer = malloc(sizeof(char) * 1024);
	if (!fmt || !buffer || (fmt[i] == '%' && !fmt[i + 1]))
		return (-1);
	if (!fmt[i])
		return (0);
	for (i = 0; fmt && fmt[i]; i++)
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(fmt, i + 1);
				if (function == NULL)
				{
					if (fmt[i + 1] == ' ' && !fmt[i + 2])
						return (-1);
					handl_buf(buffer, fmt[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(fmt, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, fmt[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
}
