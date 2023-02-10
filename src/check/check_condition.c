/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:08:40 by eunson            #+#    #+#             */
/*   Updated: 2023/02/10 10:41:29 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_min_len(t_discriminant data, t_hit_record *record, double *len)
{
	double	sqrted;

	sqrted = sqrt(data.value);
	if (*len < record->tmin || record->tmax < *len)
	{
		*len = (-data.b + sqrted) / data.a;
		if (*len < record->tmin || record->tmax < *len)
			return (False);
	}
	return (True);
}
