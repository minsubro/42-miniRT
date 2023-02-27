/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:13:48 by eunson            #+#    #+#             */
/*   Updated: 2023/02/27 12:34:34 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	check_height(t_cone *cn, t_point3 p, double *hit_height)
{
	double	max_height;


	*hit_height = v_dot(v_minus(p, cn->center), cn->normal_vector);
	max_height = cn->height;
	if (fabs(*hit_height) > max_height || (*hit_height) < 0)
		return (False);
	return (True);
}

static t_bool	update_record(t_cone *cone, t_ray *ray, \
						t_hit_record *record, t_discriminant data)
{
	double		root;
	t_point3	hit_center;
	double		hit_height;
	t_vector3 center = v_plus(cone->center, v_mult(cone->normal_vector, cone->height));

	root = (-data.b - sqrt(data.value)) / data.a;
	if (check_min_len(data, record, &root) == False)
		return (False);
	if (check_height(cone, ray_at(ray, root), &hit_height) == False)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	hit_center = v_plus(center, \
							v_mult(cone->normal_vector, hit_height));
	record->normal.x = record->p.x - center.x;
	record->normal.y = record->p.y - center.y;
	double r = cone->diameter / 2;
	double h = cone->height;
	record->normal.z = r * r * (record->p.z - center.z) / (h * h);
	record->normal = v_unit(record->normal);
	record->albedo = cone->rgb;
	//set_face_normal(ray, record);
	record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	if (record->front_face == False)
		record->normal = v_mult(record->normal, -1);
	return (True);
}


/*
static t_bool	update_record(t_cone *cone, t_ray *ray, \
						t_hit_record *record, t_discriminant data)
{
	double		root;
	t_point3	hit_center;
	double		hit_height;

	root = (-data.b - sqrt(data.value)) / data.a;
	if (check_min_len(data, record, &root) == False)
		return (False);
	if (check_height(cone, ray_at(ray, root), &hit_height) == False)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	hit_center = v_plus(cone->center, \
	 						v_mult(cone->normal_vector, hit_height));
	record->normal = v_unit(v_minus(record->p, hit_center));
	set_face_normal(ray, record);
	record->albedo = cone->rgb;
	return (True);
} 
*/

t_bool	hit_on_triangle(t_cone *cone, t_ray *ray, t_hit_record *record)
{
	t_discriminant	discriminant;

	discriminant = discriminant_cone(cone, ray);
	if (discriminant.value < 0)
		return (False);
	return (update_record(cone, ray, record, discriminant));
}

t_bool	hit_on_bottom(t_cone *cone, t_ray *ray, t_hit_record *record)
{
	t_vector3	circle_center;
	double		root;
	double		radius;
	double		diameter;

	circle_center = cone->center;
	radius = cone->diameter / 2;
	root = v_dot(v_minus(circle_center, ray->orig), cone->normal_vector) \
								/ v_dot(ray->dir_vector, cone->normal_vector);
	diameter = v_len(v_minus(circle_center, ray_at(ray, root)));
	if (radius < diameter)
		return (False);
	if (root < record->tmin || record->tmax <= root)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->albedo = cone->rgb;
	//record->normal = v_minus(circle_center, record->p);
	// record->normal = v_unit(v_minus(record->p, circle_center));
	// //set_face_normal(ray, record);
	// record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	// if (record->front_face == True)
	// 	record->normal = v_mult(record->normal, -1);
	record->normal = cone->normal_vector;
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_cone(t_cone *cone, t_ray *ray, t_hit_record *record)
{
	t_bool	hit_anything;

	hit_anything = False;
	if (hit_on_bottom(cone, ray, record) == True)
		hit_anything = True;
	if (hit_on_triangle(cone, ray, record) == True)
		hit_anything = True;
	return (hit_anything);
}
