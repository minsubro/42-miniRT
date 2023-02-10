/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:59:55 by eunson            #+#    #+#             */
/*   Updated: 2023/02/10 10:45:15 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	update_record(t_plane *plane, t_ray *ray, t_hit_record *record, double denominator)
{
	double	root;
	double	numrator;

	numrator = v_dot(v_minus(ray->orig, plane->point), plane->normal_vector);
	root = numrator / denominator;
	if (root < record->tmin || record->tmax < root)
		return (False);
	record->t = root;
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->albedo = plane->rgb;
	record->normal = plane->normal_vector;
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_plane(t_plane *plane, t_ray *ray, t_hit_record *record)
{
	double	discriminant;

	discriminant = fabs(v_dot(ray->dir_vector, plane->normal_vector));
	if (discriminant < EPSILON)
		return (False);
	return (update_record(plane, ray, record, discriminant));
}	
