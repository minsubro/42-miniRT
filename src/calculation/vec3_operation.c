/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:35:32 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:27:33 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v_len_square(t_vector3 v1)
{
	return (pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
}

double	v_len(t_vector3 v1)
{
	return (sqrt(v_len_square(v1)));
}

double	vector_value(t_vector3 v1)
{
	return (v1.x + v1.y + v1.z);
}

void	set_vec3(t_vector3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}
