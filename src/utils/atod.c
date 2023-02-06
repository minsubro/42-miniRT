/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:35:33 by eunson            #+#    #+#             */
/*   Updated: 2023/02/06 20:27:35 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_sign(char **str)
{
	int	sign;

	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	if (**str == '.')
		print_error_with_exit(INVALID_DATA);
	return (sign);
}

static double	integer_part(char **str)
{
	double	integer_part;
	
	integer_part = 0;
	while (**str && (**str >= '0' && **str <= '9'))
	{
		integer_part = integer_part * 10 + (**str - '0');
		(*str)++;
	}
	return (integer_part);
}

static double	fractional_part(char **str)
{
	double	fractional_part;

	fractional_part = 0;
	if (**str == '.')
	{
		(*str)++;
		if (!**str)
			print_error_with_exit(INVALID_DATA);
		while (**str && (**str >= '0' && **str <= '9'))
		{
			fractional_part = fractional_part * 10 + (**str - '0');
			(*str)++;
		}
		while (fractional_part > 1)
			fractional_part *= 0.1;
	}
	return (fractional_part);
}

double	atod(char *str)
{
	int		sign;
	double	res;

	sign = check_sign(&str);
	res = sign * (integer_part(&str) + fractional_part(&str));
	if (*str)
		print_error_with_exit(INVALID_DATA);
	return (res);
}