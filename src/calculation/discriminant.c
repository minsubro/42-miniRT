/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:03:52 by eunson            #+#    #+#             */
/*   Updated: 2023/02/13 12:06:26 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_discriminant	discriminant_cylinder(t_cylinder *cylinder, t_ray *ray)
{
	t_vector3		oc;
	t_discriminant	disc;
	
	oc = v_minus(ray->orig, cylinder->center);
	disc.a = v_len_square(v_cross(ray->dir_vector, cylinder->normal_vector));
	disc.b = v_dot(v_cross(ray->dir_vector, cylinder->normal_vector), \
					v_cross(oc, cylinder->normal_vector));
	disc.c = v_len_square(v_cross(oc, cylinder->normal_vector)) \
							- pow((cylinder->diameter / 2), 2);
	disc.value = pow(disc.b, 2) - disc.a * disc.c;
	return (disc);
}

t_discriminant	discriminant_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vector3		oc;
	t_discriminant	disc;
	
	oc = v_minus(ray->orig, sphere->center);
	disc.a = v_len_square(ray->dir_vector);
	disc.b = v_dot(oc, ray->dir_vector);
	disc.c = v_len_square(oc) - pow((sphere->diameter / 2), 2);
	disc.value = pow(disc.b, 2) - disc.a * disc.c;
	return (disc);
}
