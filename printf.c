#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - is a clone of printf function
 * writes the output to std out
 * @format: format string containing the characters and the specifiers
 *
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list list;
	const char *c;

	va_start(list, format);
	register int len = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (c = format; *c; c++)
	{
		if (*c == '%')
		{
			c++;

			if (*c == '%')
			{
				len += _putchar('%');

				continue;
			}
		}
		else
			len += _putchar(*c);
	}
	_putchar(-1);
	va_end(list);
	return (len);
}
