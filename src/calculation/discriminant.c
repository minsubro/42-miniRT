/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:03:52 by eunson            #+#    #+#             */
/*   Updated: 2023/02/16 19:14:45 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_discriminant	discriminant_cone(t_cone *cone, t_ray *ray)
{
	t_vector3		oc;
	t_vector3		minus_normal;
	t_discriminant	disc;
	
	oc = v_minus(ray->orig, cone->center);
	//t_vector3	tmp;
	//t_vector3 tmp = v_plus_(cone->center, v_mult(cone->normal_vector, cone->height);
	// t_vector3	tmp;
	// t_vector3	front = v_minus(ray->orig, cone->center);
	// tmp = v_mult(cone->normal_vector, cone->height);
	// oc = v_plus(front, tmp);
	// printf("front x : %f %f %f\n", front.x, front.y, front.z);
	// printf("tmp x : %f %f %f\n", tmp.x, tmp.y, tmp.z);
	// printf("p : %f %f %f\n", oc.x, oc.y, oc.z);
	minus_normal = v_mult(cone->normal_vector, -1);
	//minus_normal = cone->normal_vector;
	double c1 = v_dot(ray->dir_vector, minus_normal);
	t_vector3 c2 = v_mult(minus_normal, c1);
	double c3 = v_dot(oc, minus_normal);
	t_vector3 c4 = v_mult(minus_normal, c3);
	double	cos_square = pow(cone->height, 2) / (pow(cone->height, 2) + pow((cone->diameter / 2) , 2));
	
	disc.a = cos_square * pow(v_len(v_minus(ray->dir_vector, c2)), 2) + (cos_square - 1) * pow(c1, 2);
	disc.b = cos_square * v_dot(v_minus(ray->dir_vector, c2), (v_minus(oc, c4))) + (cos_square - 1) * (c1 * c3);
	disc.c = cos_square * pow(v_len(v_minus(oc, c4)), 2) + (cos_square - 1) * pow(c3, 2);
	
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
