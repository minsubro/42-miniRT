/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:59:55 by eunson            #+#    #+#             */
/*   Updated: 2023/02/24 02:55:01 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	get_checker_color_plane(t_hit_record *record)
{
	const int	iu = (int)floor(record->u + 0.5f);
	const int	iv = (int)floor(record->v + 0.5f);

	if ((iu + iv) % 2 == 0)
		return (c_rgb(1, 1, 1));
	else
		return (c_rgb(0, 0, 0));
}

t_rgb	get_texture_color_plane(t_plane *plane, \
	t_hit_record *record, t_texture *texture)
{
	const t_vector3	p = record->p;
	const t_vector3	n = plane->normal_vector;
	t_vector3		bitangent;
	t_vector3		tangent;
	int				pixel;

	if (fabs(n.x) > fabs(n.y))
		tangent = v_divide(c_vector3(-n.z, 0, n.x), \
			sqrt(n.x * n.x + n.z * n.z));
	else
		tangent = v_divide(c_vector3(0, n.z, -n.y), \
			sqrt(n.y * n.y + n.z * n.z));
	bitangent = v_cross(n, tangent);
	record->u = v_dot(p, tangent);
	record->v = v_dot(p, bitangent);
	record->u = record->u - floor(record->u);
	record->v = record->v - floor(record->v);
	record->u = record->u * texture->width;
	record->v = record->v * texture->height;
	pixel = *(int *)(texture->image.addr + (int)floor(record->v) * \
		texture->image.line_len + \
		(int)floor(record->u) * (texture->image.bpp / 8));
	return (int_to_rgb(pixel));
}

static t_bool	update_record(t_plane *plane, t_ray *ray, \
	t_hit_record *record, double denominator)
{
	double	root;
	double	numrator;

	numrator = v_dot(v_minus(plane->point, ray->orig), plane->normal_vector);
	root = numrator / denominator;
	if (root < record->tmin || record->tmax < root)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->normal = plane->normal_vector;
	set_face_normal(ray, record);
	get_plane_uv(plane, record);
	if (plane->texture_info.type == NORMAL)
		record->albedo = plane->rgb;
	else if (plane->texture_info.type == CHECK)
		record->albedo = get_checker_color_plane(record);
	else
		record->albedo = get_texture_color_plane(plane, \
			record, plane->texture_info.texture);
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
