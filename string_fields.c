#include "main.h"

/**
  * get_precision - it locates the precision
  *
  * @p: input format string
  * @k: input pointers
  * @params: input parameters
  *
  * Return: results
  */
char *get_precision(char *p, params_t *params, va_list k)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(k, int);
		p++;
	}
	else
	{
		while (_sidigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
