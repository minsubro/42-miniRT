/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:02:39 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/11 14:30:17 by minsukan         ###   ########.fr       */
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


t_rgb	point_light_get(t_scene *scene, t_light *light)
{
	/// diffuse
	t_rgb		diffuse;
	t_vector3	light_dir;
	double		kd;

	light_dir = v_minus(light->point, scene->record.p);
	if (scene->option.shadow == True)
	{
		if (in_shadow(scene, light_dir))
			return (c_rgb(0, 0, 0));
	}
	light_dir = v_unit(light_dir);
	kd = fmax(v_dot(scene->record.normal, light_dir), 0.0);
	diffuse = v_mult(light->rgb, kd);
	//return (diffuse);

	//specular;
	t_rgb		specular;
	t_vector3	view_dir;
	t_vector3	reflect_dir;
	double		spec;

	view_dir = v_unit(v_mult(scene->ray.dir_vector, -1));
	reflect_dir = get_reflect(v_mult(light_dir, -1), scene->record.normal);

	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), KSN);
	specular = v_mult(v_mult(light->rgb, KS), spec);

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

// 		// pong_ambient();
// 		// pong_diffuse();
// 		// pong_specular();