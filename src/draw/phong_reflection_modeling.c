/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_modeling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:02:39 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/27 16:01:24 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	in_shadow(t_scene *scene, t_vector3 light_dir)
{
	t_hit_record	rec;
	t_ray			light_ray;
	double			light_len;

	light_len = v_len(light_dir);
	light_ray = c_ray_direction(v_plus(scene->record.p, \
					v_mult(scene->record.normal, EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(scene, &light_ray, &rec))
		return (True);
	return (False);
}

t_rgb	phong_reflection_modeling(t_scene *scene)
{
	t_rgb	light_color;
	t_node	*light;

	light_color = c_rgb(0, 0, 0);
	light = scene->lights.head;
	while (light)
	{
		scene->record.in_shadow = False;
		if (light->type == LIGHT)
			light_color = v_plus(light_color, \
				point_light(scene, (t_light *)light->obj));
		else if (light->type == SPOTLIGHT)
			light_color = v_plus(light_color, \
				spotlight(scene, (t_spotlight *)light->obj));
		light = light->next;
		if (light == scene->lights.head)
			break ;
	}
	light_color = v_plus(light_color, scene->ambient->rgb);
	return (v_min(v_mult_(light_color, scene->record.albedo), c_rgb(1, 1, 1)));
}
