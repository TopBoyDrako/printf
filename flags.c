#include "main.h"

/**
 * get_flags - This function calculates active flag
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags
 */

int get_flags(const char *format, int *i)
{

	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	
	int p, ai;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ai = *i + 1; format[ai] != '\0'; ai++)
	{
		for (p = 0; FLAGS_CH[p] != '\0'; p++)
			if (format[ai] == FLAGS_CH[p])
			{
				flags |= FLAGS_ARR[p];
				break;
			}

		if (FLAGS_CH[p] == 0)
			break;
	}

	*i = ai - 1;

	return (flags);
}
