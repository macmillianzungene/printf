#include "main.h"

/**
  * get_specifier - it finds the format func
  *
  * @s: input string
  *
  * Return: results
  */
int (*get_specifier(char *s))(va_list k, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"s", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
  * get_print_func - it locates format func
  *
  * @s: input string
  * @k: input pointer
  * @params: input parameters
  *
  * Return: results
  */
int get_print_func(char *s, va_list k, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(k, params));
	return (0);
}

/**
  * get_flag - it locates the flag func
  *
  * @s: input string
  * @params: input parameters
  *
  * Return: results
  */
int get_flag(char *s, params_t, *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (1);
}

/**
  * get_modifier - it locates modifier func
  *
  * @s: input string
  * @params: input parameters
  *
  * Return: results
  */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
  * get_width - it locates the width
  *
  * @s: input string
  * @params: input parameters
  * @k: input pointer
  *
  * Return: results
  */
char *get_width(char *s, params_t *params, va_list k)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(k, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
