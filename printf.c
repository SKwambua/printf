#include <stdio.h>
#include <stddef.h>
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
	int i = 0;
	int sum = 0;
	int (*point)(va_list);

	va_start(list, format);

	if (format[0] == '%' && format[1] == '\0')
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ')
	{
		return (-1);
	}
	while (format != NULL ])
	{
		if (format[i] == '%')
		{
			if (format[1 + i] == '%')
			{
				sum += _putchar(format[i]);
				i += 2;
			}
			else
			{
				point = _putchar(format[i + 1]);
				if (point)
					sum += point(list);
				else
					sum = _putchar(format[i]) + _putchar(format[1 + i]);
				i += 2;
			}
		}
		else
			sum += _putchar(format[i]);
		i++;
	}
	va_end(list);
	return (sum);
}
