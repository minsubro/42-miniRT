/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:29 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/14 22:45:57 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_discriminant	cal_discriminant(t_sphere *sphere, t_ray *ray)
{
	t_vector3		oc;
	t_discriminant	disc;
	
	oc = v_minus(ray->orig, sphere->center);
	disc.a = v_len_square(ray->dir_vector);
	disc.b = v_dot(oc, ray->dir_vector);
	disc.c = v_len_square(oc) - pow((sphere->diameter / 2), 2);
	disc.value = pow(disc.b, 2) - disc.a * disc.c;
	return (disc);
}

void	get_sphere_uv(t_vector3 point, t_hit_record *record)
{
	double theta;
	double phi;

	theta = acos(-point.y);
	phi = atan2(-point.z, point.x) + M_PI;

	record->u = phi / (2 * M_PI);
	record->v = theta / M_PI;
}

t_rgb	get_texture_color(t_hit_record *record, t_sphere *sphere)
{
	(void)sphere;
	if (record->u <= 0.0)
		record->u = 0.0;
	if (record->u >= 1.0)
		record->u = 1.0;
	if (record->v <= 0.0)
		record->v = 0.0;
	if (record->v >= 1.0)
		record->v = 1.0;
	record->v = 1.0 - record->v;

	t_texture *earth = &(info.scene.texture_list.earth);

	int i = record->u * earth->width - 1;
	int j = record->v * earth->height - 1;

	if (i >= earth->width)
		i = earth->width - 1;
	if (j >= earth->height)
		j = earth->height - 1;

	printf("%d %d\n", i, j);	
	
	double color_scale = 1.0 / 255.0;
	char *pixle = earth->image.addr + j * earth->image.line_len + i * earth->image.bpp;
	
	t_rgb	rgb = c_rgb(color_scale * pixle[0], color_scale * pixle[1], color_scale * pixle[2]);
//	printf("%f %f %f\n", rgb.x, rgb.y, rgb.z);
	return rgb;

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
	outward_normal = v_divide(v_min(record->p, sphere->center), sphere->diameter / 2);
	get_sphere_uv(outward_normal ,record);
	record->albedo = get_texture_color(record, sphere);
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_sphere(t_sphere	*sphere, t_ray *ray, t_hit_record *record)
{
	t_discriminant	discriminant;

	discriminant = cal_discriminant(sphere, ray);
	if (discriminant.value < EPSILON)
		return (False);
	return (update_record(sphere, ray, record, discriminant));
}
