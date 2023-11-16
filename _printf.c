#include "main.h"
#include <string.h> 

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */

typedef struct {
    const char *ph;
    int (*function)(va_list);
} convert;

int _printf(const char * const format, ...)
{
	convert p[] = {
	{"%s", print_s}, {"%c", print_c},
        {"%%", print_revs},
        {"%i", print_i}, {"%d", print_d}, {"%r", print_revs},
        {"%R", print_rot13}, {"%b", print_bin},
        {"%u", print_unsigned},
        {"%o", print_oct}, {"%x", print_hex}, {"%X", print_HEX},
        {"%S", print_exc_string}, {"%p", print_pointer}
	};

	va_list args;
	int i = 0, j, length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	while (format[i] != '\0')
	{
	j = 13;
        while (j >= 0)
        {
	if (strcmp(p[j].ph, &format[i]) == 0)
		{
			length += p[j].function(args);
			i += 2;
			goto Here;
		}
			j--;
	}
	_putchar(format[i]);
        length++;
        i++;
	}
Here:
	va_end(args);
	return (length);
}

