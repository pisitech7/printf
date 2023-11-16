#include "main.h"

/**
 * print_bin - prints binary number.
 * @val: parameter.
 * Return: integer
 */
int print_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, k = 1, l;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((k << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			l = p >> (31 - i);
			_putchar(l + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}

