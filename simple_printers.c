#include "main.h"

/**
  * print_from_to - it prints the range
  *
  * @start: input start
  * @stop: input stop
  * @except: input except
  *
  * Return: results
  */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
  * print_rev - prints in reverse
  *
  * @params: input parameters
  * @k: input pointer
  *
  * Return: results
  */
int print_rev(va_list k, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(k, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
  * print_rot13 - prints the rotation of the string
  *
  * @k: input pointers
  * @params: input parameters
  *
  * Return: results
  */
int print_rot13(va_list k, params_t, *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM       nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(k, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
