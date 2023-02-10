/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:13:29 by eunson            #+#    #+#             */
/*   Updated: 2023/02/10 18:40:29 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_discriminant	cal_discriminant(t_cylinder *cylinder, t_ray *ray)
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

static t_bool	check_hit_height(t_cylinder *cylinder, t_point3 point, double *hit_height)
{
	double	max_height;

	*hit_height = v_dot(v_minus(point, cylinder->center), cylinder->normal_vector);
	max_height = cylinder->height / 2;
	if (fabs(*hit_height) > max_height)
		return (True);
	return (False);
}

static t_vector3	cal_cylinder_normal_vector(t_cylinder *cylinder, t_point3 p, double hit_height)
{
	t_vector3	circle_vector;

	//circle_vector = v_plus(cylinder->center, v_mult(cylinder->normal_vector, hit_height);
}

static t_bool	update_record(t_cylinder *cylinder, t_ray *ray, t_hit_record *record, t_discriminant data)
{
	double	root;
	double	hit_height;

	root = (-data.b - sqrt(data.value)) / data.a;
	if (check_minimum_len(data, record, &root) == False)
		return (False);
	if (check_hit_height(cylinder, ray_at(ray, root), &hit_height) == False)
		return (False);
	record->t = root;
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->albedo = cylinder->rgb;
	record->normal = cal_cylinder_normal_vector(cylinder, record->p, hit_height);
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit_record *record)
{
	t_discriminant	discriminant;

	discriminant = cal_discriminant(cylinder, ray);
	if (discriminant.value < EPSILON)
		return (False);
	return (True);
	//return (update_record(cylinder, ray, record, discriminant));
}
