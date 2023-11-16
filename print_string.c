#include "main.h"
/**
 * print_s - print a string.
 * @val: argument.
 * Return: the length of the string.
 */

int print_s(va_list val)
{
	char *s;
	int j, len;

	s = va_arg(val, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (j = 0; j < len; j++)
			_putchar(s[j]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (j = 0; j < len; j++)
			_putchar(s[j]);
		return (len);
	}
}
