/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:21:44 by eunson            #+#    #+#             */
/*   Updated: 2023/02/14 22:25:14 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	get_background_color(t_scene *scene)
{
	double	t;
	t_rgb	rgb;

	t = 0.5 * (scene->ray.dir_vector.y + 1);
	rgb = \
	(v_plus(v_mult(c_rgb(1, 1, 1), 1.0 - t), v_mult(c_rgb(0.5, 0.7, 1.0), t)));
	return (rgb);
}

t_rgb	get_color(t_scene *scene)
{
	scene->record = c_hit_record();
	if (hit(scene, &scene->ray, &scene->record))
		return (scene->record.albedo);
		//return (phong_modeling(scene));
	else
		return (get_background_color(scene));
}

