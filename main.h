#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_str(va_list list);
int print_percent(va_list list);
/**
 * struct flags_printf - struct conversion to function
 * @c: flag string
 * @f: pointer to func
 */
typedef struct flags_printf
{
	char *c;
	int (*f)(va_list);
} flags_p;

#endif
