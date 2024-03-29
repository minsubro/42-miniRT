/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:03:52 by eunson            #+#    #+#             */
/*   Updated: 2023/02/26 18:29:23 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_discriminant	discriminant_cone(t_cone *cone, t_ray *ray)
{
	t_vector3		oc;
	t_vector3		minus_normal;
	t_discriminant	disc;
	double			cos_square;

	oc = v_minus(ray->orig, v_plus(cone->center, \
					v_mult(cone->normal_vector, cone->height)));
	minus_normal = v_mult(cone->normal_vector, -1);
	cos_square = pow(cone->height, 2) / \
					(pow(cone->height, 2) + pow((cone->diameter / 2), 2));
	disc.a = cos_square * pow(v_len(v_minus(ray->dir_vector, \
				v_mult(minus_normal, v_dot(ray->dir_vector, \
				minus_normal)))), 2) + (cos_square - 1) * \
				pow(v_dot(ray->dir_vector, minus_normal), 2);
	disc.b = cos_square * v_dot(v_minus(ray->dir_vector, v_mult(minus_normal, \
				v_dot(ray->dir_vector, minus_normal))), \
				(v_minus(oc, v_mult(minus_normal, v_dot(oc, minus_normal))))) \
				+ (cos_square - 1) * (v_dot(ray->dir_vector, minus_normal) * \
				v_dot(oc, minus_normal));
	disc.c = cos_square * pow(v_len(v_minus(oc, v_mult(minus_normal, \
				v_dot(oc, minus_normal)))), 2) + (cos_square - 1) * \
				pow(v_dot(oc, minus_normal), 2);
	disc.value = pow(disc.b, 2) - disc.a * disc.c;
	return (disc);
}

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
