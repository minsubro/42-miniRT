/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:08:40 by eunson            #+#    #+#             */
/*   Updated: 2023/02/26 13:09:06 by minsukan         ###   ########.fr       */
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

t_bool	check_hit_height(t_cylinder *cy, t_point3 p, double *hit_height)
{
	double	max_height;

	*hit_height = v_dot(v_minus(p, cy->center), cy->normal_vector);
	max_height = cy->height / 2;
	if (fabs(*hit_height) > max_height)
		return (False);
	return (True);
}

void	check_dir_vector(t_vector3 vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		print_error_with_exit(INVALID_DATA);
}
