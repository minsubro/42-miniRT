/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:59:55 by eunson            #+#    #+#             */
/*   Updated: 2023/02/16 19:37:15 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_plane_uv(t_hit_record *record)
{
	record->u = record->p.x - floor(record->p.x);
	record->v = record->p.z - floor(record->p.z);
}

t_rgb	get_checker_color_plane(t_hit_record *record)
{
	double	u2 = floor(record->p.x) + floor(record->p.z);
	double	v2 = floor(record->p.y) + floor(record->p.z);
	int		i;

	i = u2 + v2;
	if (i % 2 == 0)
		return (c_rgb(0, 0, 0));
	else
		return (c_rgb(1, 1, 1));
}

static t_bool	update_record(t_plane *plane, t_ray *ray, t_hit_record *record, double denominator)
{
	double	root;
	double	numrator;

	numrator = v_dot(v_minus(plane->point, ray->orig), plane->normal_vector);
	root = numrator / denominator;
	if (root < record->tmin || record->tmax < root)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->albedo = plane->rgb;
	record->normal = plane->normal_vector;
	if (plane->texture_info.type == CHECK)
	{
		//get_plane_uv(record);
		record->albedo = get_checker_color_plane(record);
	}
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_plane(t_plane *plane, t_ray *ray, t_hit_record *record)
{
	double	discriminant;
	
	discriminant = v_dot(ray->dir_vector, plane->normal_vector);
	if (discriminant == 0)
		return (False);
	return (update_record(plane, ray, record, discriminant));
}
