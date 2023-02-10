/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_construcotr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:11:20 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/10 10:40:51 by eunson           ###   ########.fr       */
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
