#include<stdarg.h>
#include<stdio.h>
#include "main.h"

/**
 * _printf - The  functions  in  the _printf() family
 * produce output according to a format
 * Return: these functions return
 * the number of characters printed
 * @format: a character string
 */

int _printf(const char *format, ...)
{
	int count;
	int total = 0;
	va_list args;
	int flag = 0;

	if (format == NULL)
		return (0);
	va_start(args, format);
	for (count = 0; *(format + count) != '\0'; count++)
	{
		if (format[count] == '%')
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
			switch (format[count])
			{
				case 'c':
					_putchar(va_arg(args, int));
					total += 1;
					break;
				case 's':
					total += _print_str(va_arg(args, char *));
					break;
				case '%':
					_putchar('%');
					total += 1;
					break;
				default:
					_putchar('%');
					_putchar(format[count]);
					total += 2;
			}
		}
		else
		{
			_putchar(format[count]);
			total += 1;
		}
	}
	va_end(args);
	return (total);
}

