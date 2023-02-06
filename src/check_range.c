/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:50 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/06 20:27:55 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_range(double value, double min, double max)
{
	if (!(min <= value && value <= max)) 
		print_error_with_exit(INVALID_DATA);
	return (value);
}

t_point3	check_object_range(t_point3 value, double min, double max)
{
	if (!(min <= value.x && value.x <= max) || \
			!(min <= value.y && value.y <= max) || \
			!(min <= value.z && value.z <= max))
		print_error_with_exit(INVALID_DATA);
	return (value);
}
