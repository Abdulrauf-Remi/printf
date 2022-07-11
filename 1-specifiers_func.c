#include "main.h"

/**********************************PRINT BINARY*****************************************/

/**
 * print_bin - convert to binary
 * @b: number in decinal
 * Return: number of chars printed
 */
int print_bin(va_list b)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/*********************************PRINT UNSIGNED INTEGER*************************************/

/**
 * print_unsig - function that prints unsigned number
 * @u: unsigned number
 * Descriptions: prints unsigned number with putchar
 * Return: size the output
 */
int print_unsig(va_list u)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(u, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/*****************************************PRINT HEXADECIMAL*****************************************/

/**
 * print_hex - function that prints an unsigned int in hexadecimal
 * @n: unsigned to be printed
 * @c: case of printing (0 = lower, 1 = upper)
 * Descriptions: prints unsigned in hexadecimal with _putchar
 * Return: size the output
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int len, powten, j, digit, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 16;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/***********************************PRINT HEXDECIMAL IN LOWERCASE*********************************/

/**
 * print_x - takes an unsigned int an prints it in lowercase hex
 * @x: unsigned int to print
 * Descriptions: prints in lowercase hex with _putchar
 * Return: size of the output
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/***********************************PRINT HEXADECIMAL IN UPPERCASE******************************/

/**
 * print_X - takes an unsigned int an prints it in uppercase hex
 * @X: unsigned int to print
 * Descriptions: prints in uppercase hex with _putchar
 * Return: size of the output
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
