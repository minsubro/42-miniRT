/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_construcotr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:11:20 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/10 18:49:09 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	c_ray(t_camera *camera, double u, double v)
{
	t_ray		ray;
	t_viewport	viewport;

	viewport = camera->viewport;
	ray.orig = camera->point;
	ray.dir_vector = v_unit(v_minus(v_plus(v_plus(viewport.left_bottom, v_mult(viewport.h_vector, u)), v_mult(viewport.v_vector, v)), camera->point));
	return (ray);
}

t_ray	c_ray_direction(t_point3 origin, t_vector3 dir)
{
	t_ray	ray;

	ray.orig = origin;
	ray.dir_vector = v_unit(dir);
	return (ray);
}
