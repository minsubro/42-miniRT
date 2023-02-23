/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_construcotr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:30:24 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:34:04 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_viewport	c_viewport(t_camera *camera)
{
	t_viewport	viewport;
	t_vector3	w;
	t_vector3	u;
	t_vector3	v;
	double		h;

	h = tan(degree_to_radian((camera->fov)) / 2);
	viewport.height = 2.0 * h;
	viewport.width = viewport.height * (16 / 9);
	v_unit(v_minus_(camera->dir_vector));
	v_unit(v_cross(camera->v_up, w));
	v_cross(w, u);
	viewport.h_vector = v_mult(u, viewport.width);
	viewport.v_vector = v_mult(v, viewport.height);
	viewport.left_bottom = v_minus(v_minus(v_minus(camera->point, \
		v_divide(viewport.h_vector, 2)), v_divide(viewport.v_vector, 2)), w);
	return (viewport);
}

t_viewport	sub_viewport(t_camera *camera)
{
	t_viewport	viewport;
	double		theta;
	double		h;

	theta = degree_to_radian(camera->fov);
	h = tan(theta / 2);
	viewport.height = 2.0 * h;
	viewport.width = viewport.height;
	viewport.h_vector = c_vector3(viewport.width, 0, 0);
	viewport.v_vector = c_vector3(0, viewport.height, 0);
	viewport.left_bottom = \
			v_minus(v_minus(v_minus(camera->point, \
			v_divide(viewport.h_vector, 2)), \
			v_divide(viewport.v_vector, 2)), \
			c_vector3(0, 0, 1));
	return (viewport);
}
