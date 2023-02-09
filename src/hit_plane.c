/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:59:55 by eunson            #+#    #+#             */
/*   Updated: 2023/02/10 02:01:20 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_face_normal(t_ray *ray, t_hit_record *record)
{
	record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	if (record->front_face == False)
		record->normal = v_mult(record->normal, -1);
}

t_bool	is_intersection(t_plane *plane, t_ray *ray)
{
	if (v_dot(plane->normal_vector, ray->dir_vector) == 0)
		return (False);
	return (True);
}

static t_bool	update_record(t_plane *plane, t_ray *ray, t_hit_record *record, t_point3 intersection)
{
	double	root;

	root = v_len((t_vector3)intersection);
	if (root < record->tmin || record->tmax < root)
		return (False);
	record->t = root;
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->normal = plane->normal_vector;
	record->albedo = plane->rgb;
	set_face_normal(ray, record);
	return (True);
}

t_point3	find_intersection(t_plane *plane, t_ray *ray)
{
	t_vector3		dir;
	t_vector3		normal;
	t_point3		point;
	t_point3		intersection;
	double		weight;

	dir = ray->dir_vector;
	normal = plane->normal_vector;
	point = plane->point;
	weight = (normal.x * point.x + normal.y * point.y + normal.z + point.z) / \
				(normal.x * dir.x + normal.y * dir.y + normal.z + dir.z);
	intersection.x = weight * dir.x;
	intersection.y = weight * dir.y;
	intersection.z = weight * dir.z;
	return (intersection);
}

t_bool	hit_plane(t_plane *plane, t_ray *ray, t_hit_record *record)
{
	t_point3	intersection;

	if (is_intersection(plane, ray) == False)
		return (False);
	intersection = find_intersection(plane, ray);
	return (update_record(plane, ray, record, intersection));
}	
