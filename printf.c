#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_op - select function for conversion character
 * @b: char to check
 * Return: pointer to function
 */
int (*get_op(const char b))(va_list)
{
	int i = 0;

	flags_p fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent}
	};
	while (i < 3)
	{
		if (b == fp[i].c[0])
		{
		return (fp[i].f);
		}
		i++;
	}
	return (NULL);
}

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
	int sum= 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	va_start(list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = get_op(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				sum++;
				i++;
			}
			else
			{
				sum += func(list);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			sum++;
			i++;
		}
	}
	va_end(list);
	return (sum);
}
