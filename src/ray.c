/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:02:39 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/10 17:27:08 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_point3 origin, t_vector3 dir)
{
	t_ray	ray;

	ray.orig = origin;
	ray.dir_vector = v_unit(dir);
	return (ray);
}

t_vector3	reflect(t_vector3 v, t_vector3 n)
{
	return (v_minus(v, v_mult(n, v_dot(v, n) * 2)));
}

t_bool	in_shadow(t_scene *scene, t_vector3 light_dir)
{
	t_hit_record	rec;
	t_ray			light_ray;
	double			light_len;

	light_len = v_len(light_dir);
	light_ray = ray(v_plus(scene->record.p, v_mult(scene->record.normal, EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(scene, &light_ray, &rec))
		return (True);
	return (False);
}


t_rgb	point_light_get(t_scene *scene, t_light *light)
{
	/// diffuse
	t_rgb		diffuse;
	t_vector3	light_dir;
	double		kd;

	light_dir = v_minus(light->point, scene->record.p);
	
	if (in_shadow(scene, light_dir))
		return (c_rgb(0, 0, 0));
	light_dir = v_unit(light_dir);
	kd = fmax(v_dot(scene->record.normal, light_dir), 0.0);
	diffuse = v_mult(light->rgb, kd);
	//return (diffuse);

	//specular;
	t_rgb		specular;
	t_vector3	view_dir;
	t_vector3	reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	view_dir = v_unit(v_mult(scene->ray.dir_vector, -1));
	reflect_dir = reflect(v_mult(light_dir, -1), scene->record.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = v_mult(v_mult(light->rgb, ks), spec);

	double	brightness;
	brightness = light->brightness_ratio * LUMEN;

	return (v_mult(v_plus(v_plus(scene->ambient->rgb, diffuse), specular), brightness));
}

t_rgb	phong_lightting(t_scene *scene)
{
	t_rgb	light_color;
	t_list	*light_list;

	light_color = c_rgb(0, 0, 0);
	light_list = scene->lights;
	while (light_list)
	{
		light_color = v_plus(light_color, point_light_get(scene, (t_light *)light_list->obj));
		light_list = light_list->next;
	}

	light_color = v_plus(light_color, scene->ambient->rgb);
	return (v_min(v_mult_(light_color, scene->record.albedo), c_rgb(1, 1, 1)));
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = v_plus(ray->orig, v_mult(ray->dir_vector, t));
	return (at);
}

t_rgb	ray_color(t_scene *scene)
{
	double	t;

	scene->record = c_hit_record();
	if (hit(scene, &scene->ray, &scene->record))
	{
		return (phong_lightting(scene));
	}
	else
	{
		t = 0.5 * (scene->ray.dir_vector.y + 1.0);
		return (v_plus(v_mult(c_rgb(1, 1, 1), 1.0 - t), v_mult(c_rgb(0.5, 0.7, 1.0), t)));
	}	
}