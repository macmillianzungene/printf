#include "main.h"

/**
  * _isdigit - it checks for digits
  *
  * @c: input character
  *
  * Return: results
  */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
  * _strlen - prints the length of a string
  *
  * @s: input string
  *
  * Return: results
  */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
  * print_number - prints number
  *
  * @str: input string
  * @params: input parameters
  *
  * Return: results
  */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
  * print_number_right_shift - prints number
  *
  * @str: input string
  * @params: input parameters
  *
  * Return: results
  */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, _neg, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = _neg = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !_neg) ||
			(!params->plus_flag && params->space_flag && !_neg))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !_neg && pad_char == '0' & !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !_neg &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !_neg && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !_neg &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !_neg && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !_neg &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
  * print_number_left_shift - prints number
  *
  * @str: input string
  * @params: input parameters
  *
  * Return: results
  */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, _neg, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = _neg = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !_neg && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !_neg && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
