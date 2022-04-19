#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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
				len += putchar('%');
				continue;
			}

		}
		else
			len += putchar(*c);
	}
	putchar(-1);
	va_end(list);
	return (len);

}
int main()
{
	_printf("mustwork");
	return (0);

}
