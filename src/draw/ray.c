/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:02:39 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/12 19:50:36 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	in_shadow(t_scene *scene, t_vector3 light_dir)
{
	t_hit_record	rec;
	t_ray			light_ray;
	double			light_len;

	light_len = v_len(light_dir);
	light_ray = c_ray_direction(v_plus(scene->record.p, v_mult(scene->record.normal, EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(scene, &light_ray, &rec))
		return (True);
	return (False);
}

t_rgb	get_diffuse_rgb(t_scene *scene, t_light *light)
{
	t_vector3	light_dir;
	double		kd;

	light_dir = v_minus(light->point, scene->record.p);
	if (scene->option.shadow == True)
	{
		if (in_shadow(scene, light_dir) == True)
			return (c_rgb(0,0,0));
	}
	light_dir = v_unit(light_dir);
	kd = fmax(v_dot(scene->record.normal, light_dir), 0.0);
	return (v_mult(light->rgb, kd));
}

t_rgb	get_specular_rgb(t_scene *scene, t_light *light)
{
	t_vector3	view_dir;
	t_vector3	light_dir;
	t_vector3	reflect_dir;
	double		spec;
	
	view_dir = v_unit(v_mult(scene->ray.dir_vector, -1));
	light_dir = v_unit(v_minus(light->point, scene->record.p));
	reflect_dir = get_reflect(v_mult(light_dir, -1), scene->record.normal);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), KSN);
	return (v_mult(v_mult(light->rgb, KS), spec));
}

t_rgb	phong_shading(t_scene *scene, t_light *light)
{
	t_rgb		diffuse;
	t_rgb		specular;
	double		brightness;

	diffuse = get_diffuse_rgb(scene, light);
	specular = get_specular_rgb(scene, light);
	brightness = light->brightness_ratio * LUMEN;
	return (v_mult(v_plus(v_plus(scene->ambient->rgb, diffuse), specular), brightness));
}

t_rgb	phong_modeling(t_scene *scene)
{
	t_rgb	light_color;
	t_list	*light_list;

	light_color = c_rgb(0, 0, 0);
	light_list = scene->lights;
	while (light_list)
	{
		light_color = v_plus(light_color, phong_shading(scene, (t_light *)light_list->obj));
		light_list = light_list->next;
	}
	light_color = v_plus(light_color, scene->ambient->rgb);
	return (v_min(v_mult_(light_color, scene->record.albedo), c_rgb(1, 1, 1)));
}