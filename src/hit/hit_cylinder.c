/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:13:29 by eunson            #+#    #+#             */
/*   Updated: 2023/02/24 02:57:56 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	update_record(t_cylinder *cylinder, t_ray *ray, \
									t_hit_record *record, t_discriminant data)
{
	double		root;
	t_point3	hit_center;
	double		hit_height;

	root = (-data.b - sqrt(data.value)) / data.a;
	if (check_min_len(data, record, &root) == False)
		return (False);
	if (check_hit_height(cylinder, ray_at(ray, root), &hit_height) == False)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	hit_center = v_plus(cylinder->center, \
								v_mult(cylinder->normal_vector, hit_height));
	record->normal = v_unit(v_minus(record->p, hit_center));
	set_face_normal(ray, record);
	record->albedo = cylinder->rgb;
	return (True);
}

t_bool	hit_on_circle(t_cylinder *cy, t_ray *ray, \
						t_hit_record *record, double height)
{
	t_vector3	circle_center;
	double		root;
	double		radius;
	double		diameter;

	circle_center = v_plus(cy->center, v_mult(cy->normal_vector, height));
	radius = cy->diameter / 2;
	root = v_dot(v_minus(circle_center, ray->orig), cy->normal_vector) \
								/ v_dot(ray->dir_vector, cy->normal_vector);
	diameter = v_len(v_minus(circle_center, ray_at(ray, root)));
	if (fabs(radius) < fabs(diameter))
		return (False);
	if (root < record->tmin || record->tmax < root)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->albedo = cy->rgb;
	if (0 < height)
		record->normal = cy->normal_vector;
	else
		record->normal = v_mult(cy->normal_vector, -1);
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_on_rectangle(t_cylinder *cylinder, t_ray *ray, t_hit_record *record)
{
	t_discriminant	discriminant;

	discriminant = discriminant_cylinder(cylinder, ray);
	if (discriminant.value < 0)
		return (False);
	return (update_record(cylinder, ray, record, discriminant));
}

t_bool	hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit_record *record)
{
	t_bool	hit_anything;

	hit_anything = False;
	if (hit_on_circle(cylinder, ray, record, cylinder->height / 2) == True)
		hit_anything = True;
	if (hit_on_circle(cylinder, ray, record, -(cylinder->height / 2)) == True)
		hit_anything = True;
	if (hit_on_rectangle(cylinder, ray, record) == True)
		hit_anything = True;
	return (hit_anything);
}
