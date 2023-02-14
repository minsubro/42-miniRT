/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:08:40 by eunson            #+#    #+#             */
/*   Updated: 2023/02/14 22:15:41 by minsukan         ###   ########.fr       */
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
