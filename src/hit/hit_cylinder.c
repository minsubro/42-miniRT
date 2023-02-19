/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:13:29 by eunson            #+#    #+#             */
/*   Updated: 2023/02/19 18:08:39 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_rgb	get_cylinder_rectangle_check_color(t_cylinder *cylinder, t_hit_record *record)
{
	double scale = 2;
	t_vector3	center = v_minus(cylinder->center, v_mult(cylinder->normal_vector, cylinder->height / 2));
	// t_vector3	center = v_minus(cylinder->center, c_vector3(0, cylinder->height / 2 , 0));
	//t_vector3	tmp = v_mult(cylinder->normal_vector, cylinder->height / 2);
	//t_vector3	tmp2 = c_vector3(0, cylinder->height / 2 , 0);
	record->u = (0.5 + scale * atan2(record->p.z - center.z, record->p.x - center.x)) / (2 * M_PI);
	record->v =  (record->p.y - center.y) / cylinder->height;
	double u = record->u * 10.0;
	double v = record->v * 6;
	int s = (int)u % 2;
	int t = (int)v % 2;
	if (s == t)
		return (c_rgb(0, 0, 0));
	else
		return (c_rgb(1, 1, 1));
}

t_rgb	get_cylinder_color(t_cylinder *cylinder, t_hit_record *record)
{
	if (cylinder->texture_info.type == NORMAL)
		return (cylinder->rgb);
	else if (cylinder->texture_info.type == CHECK)
		return (get_cylinder_rectangle_check_color(cylinder, record));
	else
		return (c_rgb(0, 0, 0));
}

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
	//cylinder_uv_setting(cylinder ,record);
	record->albedo = get_cylinder_color(cylinder ,record);
	hit_center = v_plus(cylinder->center, \
								v_mult(cylinder->normal_vector, hit_height));
	record->normal = v_unit(v_minus(record->p, hit_center));
	set_face_normal(ray, record);
	return (True);
}

t_vector2	c_vector2(double x, double y)
{
	t_vector2	v1;

	v1.x = x;
	v1.y = y;

	return (v1);
}

double	v2_dot(t_vector2 v1, t_vector2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_rgb	get_cylinder_top_check_pattern(t_cylinder *cy, t_hit_record *record)
{
	// (void)record;
	t_vector3	center = v_minus(cy->center, v_mult(cy->normal_vector, cy->height / 2));
	// //t_vector3	top_normal = cy->normal_vector;
	
	// t_vector2	top_uv = c_vector2(center.x, center.y);
	
	// double top_u = v2_dot(top_uv, c_vector2(1, 0)) * (1.0 / (2.0 * M_PI * (cy->diameter / 2)));
	// double top_v = v2_dot(top_uv, c_vector2(0, 1)) * (1.0 / cy->height);
	
	// if ((int)(floor(top_u) + floor(top_v)) % 2 == 0)
	// 	return (c_rgb(0, 0, 0));
	// else
	// 	return (c_rgb(1, 1, 1));

	t_vector3	origin = v_minus(record->p, center);
	
	double theta = atan2(origin.y, origin.x);
	if (theta < 0)
		theta += 2 * M_PI;
	double u = theta / (2 * M_PI) + 0.5;
	double v = origin.z / cy->height;
	double size = 12;
	v *= 0.5;

	int check = ((int)(u * size) + (int)(v * size)) % 2;
	
	if (check == 0)
		return (c_rgb(0, 0, 0));
	else
		return (c_rgb(1, 1, 1));

	// if ((int)(u * size) % 2 == 0) {
	// 	if ((int)(v * size) % 2 == 0)
	// 	{
	// 		return (c_rgb(0, 0, 0));
	// 	}
	// 	else
	// 		return (c_rgb(1, 1, 1));
	// }
	// else {
	// 	if ((int)(v / size) % 2 == 0)
	// 		return (c_rgb(1, 1, 1));
	// 	else
	// 		return (c_rgb(0, 0, 0));
	// }
}

t_rgb	get_cylinder_top_color(t_cylinder *cy, t_hit_record *record)
{
	if (cy->texture_info.type == NORMAL)
		return (cy->rgb);
	if (cy->texture_info.type == CHECK)
		return (get_cylinder_top_check_pattern(cy, record));
	return (c_rgb(1, 1, 1));
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
	if (height > 0)
		record->albedo = get_cylinder_top_color(cy, record);
	else
		record->albedo = cy->rgb;
		//record->albedo = get_cylinder_top_color(cy, record);
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
	if (hit_on_circle(cylinder, ray, record, cylinder->height / 2) == True) // top
		hit_anything = True;
	if (hit_on_circle(cylinder, ray, record, -(cylinder->height / 2)) == True) // bottom
		hit_anything = True;
	if (hit_on_rectangle(cylinder, ray, record) == True)
		hit_anything = True;
	return (hit_anything);
}
