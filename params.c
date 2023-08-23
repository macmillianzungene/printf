#include "main.h"

/**
  * init_params - clears struct fields
  *
  * @params: input parameter
  * @k: input pointer
  *
  * Return: results
  */
void init_params(params_t *params, va_list k)
{
	params->unsigne = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UNIT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)k;
}
