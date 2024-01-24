/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:42:57 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 21:18:16 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	v_plus(t_vector3 v1, t_vector3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

void	v_plus_(t_vector3 *v1, t_vector3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

t_vector3	v_minus(t_vector3 v1, t_vector3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vector3	v_minus_(t_vector3 point)
{
	t_vector3	v1;

	v1.x = -point.x;
	v1.y = -point.y;
	v1.z = -point.z;
	return (v1);
}
