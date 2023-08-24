#include "main.h"

/**
  * _printf - prints all
  *
  * @format: input string
  *
  * Return: results
  */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list k;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(k, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, k);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, k);
		p = get_precision(p, &params, k);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, k, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(k);
	return (sum);
}
