/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:29 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/20 15:32:33 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_sphere_uv(t_vector3 normal, t_hit_record *record)
{
	const double	theta = atan2(normal.x, normal.z);
	const double	radius = v_len(normal);

	record->u = 1.0 - ((theta / (2 * M_PI)) + 0.5);
	record->v = 1.0 - (acos(normal.y / radius)) / M_PI;	
}

t_rgb	get_texture_color_sphere(t_hit_record *record, t_texture *texture)
{
	const double v = 1.0 - record->v;
	const double x = record->u * (texture->width - 1);
	const double y = v * (texture->height - 1);
	
	int pixel = *(int *)(texture->image.addr + (int)round(y) * texture->image.line_len + (int)round(x) * (texture->image.bpp / 8)); 
	int r = ((pixel >> 16) & 255);
	int g = ((pixel >> 8) & 255);
	int b = ((pixel >> 0) & 255);
	t_rgb	rgb = c_rgb((double)r / 255.0, (double)g / 255.0, (double)b / 255.0);
	return (rgb);

}

t_rgb	get_checker_pattern(t_hit_record *record)
{
	const double	u2 = floor(record->u * 12);
	const double	v2 = floor(record->v * 12);
	int				i;

	i = u2 + v2;
	if (i % 2 == 0)
		return (c_rgb(0, 0, 0));
	else
		return (c_rgb(1, 1, 1));
}


t_rgb	get_sphere_color(t_sphere *sphere, t_hit_record *record)
{
	if (sphere->texture_info.type == NORMAL)
		return (sphere->rgb);
	else if (sphere->texture_info.type == CHECK)
		return (get_checker_pattern(record));
	else
		return (get_texture_color_sphere(record, sphere->texture_info.texture));
}

static t_bool	update_record \
	(t_sphere *sphere, t_ray *ray, t_hit_record *record, t_discriminant data)
{
	double	root;
	t_vector3	outward_normal;

	root = (-data.b - sqrt(data.value)) / data.a;
	if (check_min_len(data, record, &root) == False)
		return (False);
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->normal = v_unit(v_divide(v_minus(record->p, sphere->center), (sphere->diameter / 2)));
	outward_normal = v_divide(v_minus(record->p, sphere->center), sphere->diameter / 2);
	set_face_normal(ray, record);              
	get_sphere_uv(outward_normal ,record);
	record->albedo = get_sphere_color(sphere, record);
	return (True);
}

t_bool	hit_sphere(t_sphere	*sphere, t_ray *ray, t_hit_record *record)
{
	t_discriminant	discriminant;

	discriminant = discriminant_sphere(sphere, ray);
	if (discriminant.value < EPSILON)
		return (False);
	return (update_record(sphere, ray, record, discriminant));
}
