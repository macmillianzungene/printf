#include "main.h"

/**
  * print_hex - prints lowercase unsigned numbers
  *
  * @k: input pointer
  * @params: input parameters
  *
  * Return: results
  */
int print_hex(va_list k, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(k, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(k, unsigned int);
	else
		l = (unsigned int)va_arg(k, unsigned int);

	*str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
  * print_HEX - prints uppercase unsigned numbers
  *
  * @k: input pointer
  * @params: input parameters
  *
  * Return: results
  */
int print_HEX(va_list k, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(k, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(k, unsigned int);
	else
		l = (unsigned int)va_arg(k, unsigned int);

	*str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
  * print_binary - prints binary numbers
  *
  * @k: input pointer
  * @params: input parameters
  *
  * Return: results
  */
int print_binary(va_list k, params_t *params)
{
	unsigned int n = va_arg(k, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
  * print_octal - prints octal numbers
  *
  * @k: input pointer
  * @params: input parameters
  *
  * Return: results
  */
int print_octal(va_list k, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(k, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(k, unsigned int);
	else
		l = (unsigned int)va_arg(k, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
