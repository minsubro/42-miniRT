/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:34:47 by eunson            #+#    #+#             */
/*   Updated: 2023/02/27 16:07:45 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	get_diffuse_spot(t_scene *scene, t_spotlight *light)
{
	t_vector3	light_dir;
	double		kd;

	light_dir = v_minus(light->point, scene->record.p);
	if (scene->option.shadow == True)
	{
		if (in_shadow(scene, light_dir) == True)
		{
			scene->record.in_shadow = True;
			return (c_rgb(0, 0, 0));
		}
	}
	light_dir = v_unit(light_dir);
	kd = fmax(v_dot(scene->record.normal, light_dir), 0.0);
	return (v_mult(light->rgb, kd));
}

static t_rgb	get_specular_spot(t_scene *scene, t_spotlight *light)
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

static double	smoothstep(double a, double b, double t)
{
	t = fmax(0.0, fmin((t - a) / (b - a), 1.0f));
	return (t * t * (3.0 - 2.0 * t));
}

static t_vector3	get_light_intensity(t_scene *scene, t_spotlight *light)
{
	t_vector3	light_dir;
	double		intensity;
	t_vector3	light_intensity;

	light_dir = v_unit(v_minus(light->point, scene->record.p));
	intensity = smoothstep(OUTERCUTOFF, CUTOFF, \
							v_dot(light_dir, v_minus_(light->dir)));
	light_intensity = v_mult(light->rgb, intensity);
	return (light_intensity);
}

t_rgb	spotlight(t_scene *scene, t_spotlight *light)
{
	t_rgb		diffuse;
	t_rgb		specular;
	double		brightness;
	t_vector3	light_intensity;

	diffuse = get_diffuse_spot(scene, light);
	if (scene->record.in_shadow == True)
		return (c_rgb(0, 0, 0));
	specular = get_specular_spot(scene, light);
	brightness = light->brightness_ratio * LUMEN;
	light_intensity = get_light_intensity(scene, light);
	return (v_mult((v_plus(v_mult_(v_plus(scene->ambient->rgb, \
		diffuse), specular), light_intensity)), brightness));
}
