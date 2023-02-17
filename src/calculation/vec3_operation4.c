/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:33 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/17 16:27:25 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v_dot(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector3	v_cross(t_vector3 v1, t_vector3 v2)
{
	t_vector3	v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}

t_vector3	v_unit(t_vector3 v1)
{
	double	len;

	len = v_len(v1);
	if (len == 0)
		print_error_with_exit(ZERO_DENOMINATOR);
	v1.x /= len;
	v1.y /= len;
	v1.z /= len;
	return (v1);
}

t_vector3	v_min(t_vector3 v1, t_vector3 v2)
{
	if (v1.x > v2.x)
		v1.x = v2.x;
	if (v1.y > v2.y)
		v1.y = v2.y;
	if (v1.z > v2.z)
		v1.z = v2.z;
	return (v1);
}
