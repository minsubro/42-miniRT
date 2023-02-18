/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:59:55 by eunson            #+#    #+#             */
/*   Updated: 2023/02/18 17:34:03 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* 보류 */
// void	get_plane_uv(t_hit_record *record)
// {
	
// }

// t_rgb	get_checker_color_plane(t_hit_record *record)
// {
// 	double	u2 = floor(record->p.x) + floor(record->p.z);
// 	double	v2 = floor(record->p.y) + floor(record->p.z);
// 	int		i;

// 	i = u2 + v2;
// 	if (i % 2 == 0)
// 		return (c_rgb(0, 0, 0));
// 	else
// 		return (c_rgb(1, 1, 1));
// }

// t_rgb	plane_checkerboard_xy(t_hit_record *record)
// {
// 	double	u;
// 	double	v;

// 	u = record->p.x
// 		* (1 + fabs(record->normal.x)) * fabs(record->normal.z);
// 	v = record->p.y
// 		* (1 + fabs(record->normal.y)) * fabs(record->normal.z);
// 	if ((record->p.x > 0 && record->p.y > 0)
// 		|| (record->p.x < 0 && record->p.y < 0))
// 	{
// 		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
// 			return (c_rgb(0, 0, 0));
// 		else
// 			return (c_rgb(1, 1, 1));
// 	}
// 	else
// 	{
// 		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
// 			return (c_rgb(0, 0, 0));
// 		else
// 			return (c_rgb(1, 1, 1));
// 	}
// }

// t_rgb	plane_checkerboard_xz(t_hit_record	*record)
// {
// 	double u;
// 	double v;
	
// 	u = record->p.x
// 		* (1 + fabs(record->normal.x)) * fabs(record->normal.y);
// 	v = record->p.z
// 		* (1 + fabs(record->normal.z)) * fabs(record->normal.y);
// 	if ((record->p.x > 0 && record->p.z > 0)
// 		|| (record->p.x < 0 && record->p.z < 0))
// 	{
// 		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
// 			return (c_rgb(0, 0, 0));
// 		else
// 			return (c_rgb(1, 1, 1));
// 	}
// 	else
// 	{
// 		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
// 			return (c_rgb(0, 0, 0));
// 		else
// 			return (c_rgb(1, 1, 1));
// 	}
// }

// t_rgb	plane_checkerboard_zy(t_hit_record *record)
// {
// 	double	u;
// 	double	v;

// 	u = record->p.z
// 		* (1 + fabs(record->normal.z)) * fabs(record->normal.x);
// 	v = record->p.y
// 		* (1 + fabs(record->normal.y)) * fabs(record->normal.x);
// 	if ((record->p.z > 0 && record->p.y > 0)
// 		|| (record->p.z < 0 && record->p.y < 0))
// 	{
// 		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
// 			return (c_rgb(0, 0, 0));
// 		else
// 			return (c_rgb(1, 1, 1));
// 	}
// 	else
// 	{
// 		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
// 			return (c_rgb(0, 0, 0));
// 		else
// 			return (c_rgb(1, 1, 1));
// 	}
// }

// t_rgb	get_checker_color_plane(t_hit_record *record)
// {
// 	if (sqrt(record->normal.x * record->normal.x
// 			+ record->normal.y * record->normal.y) == 1
// 		&& record->normal.x != 0 && record->normal.y != 0
// 		&& record->normal.x != 1 && record->normal.x != -1
// 		&& record->normal.y != 1 && record->normal.y != -1)
// 		plane_checkerboard_xz(record);
// 	else if (fabs(record->normal.x) > 0.8
// 		&& record->normal.x != 1 && record->normal.x != -1
// 		&& record->normal.y != 0 && record->normal.z != 0)
// 		return (plane_checkerboard_zy(record));
// 	else if (fabs(record->normal.y) > 0.8
// 		&& record->normal.y != 1 && record->normal.y != -1
// 		&& record->normal.x != 0 && record->normal.z != 0)
// 		return (plane_checkerboard_xz(record));
// 	else if (fabs(record->normal.z) > 0.8
// 		&& record->normal.z != 1 && record->normal.z != -1
// 		&& record->normal.x != 0 && record->normal.y != 0)
// 		return (plane_checkerboard_zy(record));
// 	else if (record->normal.x == 0)
// 	{
// 		if (record->normal.y == 1 || record->normal.y == -1)
// 			return (plane_checkerboard_xz(record));
// 		else if (record->normal.x == 1 || record->normal.x == -1)
// 			return (plane_checkerboard_zy(record));
// 		else
// 			return (plane_checkerboard_xy(record));
// 	}
// 	else if (record->normal.z == 0)
// 	{
// 		if ((record->normal.y == 1 || record->normal.y == -1))
// 			plane_checkerboard_xz(record);
// 		else
// 			plane_checkerboard_zy(record);
// 	}
// 	else
// 	{
// 		if (record->normal.x == 1 || record->normal.x == -1)
// 			plane_checkerboard_zy(record);
// 		else if (record->normal.y == 1 || record->normal.y == -1)
// 			plane_checkerboard_xz(record);
// 		else
// 			plane_checkerboard_xy(record);
// 	}
// 	return (c_rgb(1, 1, 1));
// }

t_rgb	get_checker_color_plane(t_hit_record *record)
{
	int iu = (int)floor(record->u + 0.5f);
	int iv = (int)floor(record->v + 0.5f);
	//printf("%f %f", record->u, record->v);
	if ((iu + iv) % 2 == 0)
		return (c_rgb(1, 1, 1));
	else
		return (c_rgb(0, 0, 0));
}

t_rgb	int_to_rgb(int pixel)
{
	t_rgb	rgb;

	rgb.x = (double)((pixel >> 16) & 255) / 255.0;
	rgb.y = (double)((pixel >> 8) & 255) / 255.0;
	rgb.y = (double)((pixel >> 0) & 255)/ 255.0;
	return (rgb);
}

void	get_plane_uv(t_plane *plane, t_hit_record *record)
{
	t_vector3	t = v_unit(v_cross(plane->normal_vector, c_vector3(0, 0, 1)));	
	t_vector3	b = v_cross(plane->normal_vector, t);

	record->u = v_dot(v_minus(record->p, plane->point), t) / v_dot(t, t);
	record->v = v_dot(v_minus(record->p, plane->point), b) / v_dot(b, b);
}

t_rgb	get_texture_color_plane(t_plane *plane ,t_hit_record *record, t_texture *texture)
{
	// int x = (int)(record->u * texture->width);
	// int y = (int)(record->v * texture->height);
	(void)record;
	(void)plane;
	// t_vector3	planeNormal = plane->normal_vector;
	// t_vector3	planePoint = plane->point;
	// double u;
	// double v;
	// t_vector3	basis1 = v_unit(v_cross(planeNormal, c_vector3(0, 0, 1)));
	// t_vector3	basis2 = v_unit(v_cross(planeNormal, basis1));
	// t_vector3	planePointLocal = v_minus(planePoint, v_mult(planeNormal ,v_dot(planePoint, planeNormal)));
	// u = v_dot(planePointLocal, basis1);
	// v = v_dot(planePointLocal, basis2);

	t_vector3	p = record->p;
	t_vector3	n  = plane->normal_vector;

	t_vector3	tangent;
	if (fabs(n.x) > fabs(n.y))
		tangent = v_divide(c_vector3(-n.z, 0, n.x), sqrt(n.x * n.x + n.z * n.z));
	else
		tangent = v_divide(c_vector3(0, n.z, -n.y), sqrt(n.y * n.y + n.z * n.z));
	t_vector3	bitangent = v_cross(n, tangent);
	
	record->u = v_dot(p, tangent);
	record->v = v_dot(p, bitangent);
	//printf("%f %f\n", x, y);
	//return (c_rgb(0, 0, 0));
	record->u = record->u - floor(record->u);
	record->v = record->v - floor(record->v);
	int x = record->u * texture->width;
	int y = record->v * texture->height;
	int pixel = *(int *)(texture->image.addr + (int)floor(y) * texture->image.line_len + (int)floor(x) * (texture->image.bpp / 8));
	return (int_to_rgb(pixel));
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
	record->normal = plane->normal_vector;
	get_plane_uv(plane, record);
	if (plane->texture_info.type == NORMAL)
		record->albedo = plane->rgb;
	else if (plane->texture_info.type == CHECK)
		record->albedo = get_checker_color_plane(record);
	else
		record->albedo = get_texture_color_plane(plane ,record, plane->texture_info.texture);
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
