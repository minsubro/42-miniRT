/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:26:01 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:26:16 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	v_mult(t_vector3 v1, double s)
{
	v1.x *= s;
	v1.y *= s;
	v1.z *= s;
	return (v1);
}

t_vector3	v_mult_(t_vector3 v1, t_vector3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vector3	v_divide(t_vector3 v1, double s)
{
	v1.x *= 1 / s;
	v1.y *= 1 / s;
	v1.z *= 1 / s;
	return (v1);
}
