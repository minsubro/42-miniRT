/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_construcotr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:30:24 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/09 23:27:22 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_viewport	c_viewport(t_point3	point, t_vector3 dir_vector, double fov)
{
	t_viewport	viewport;

	viewport.height = 2.0;
	viewport.width = viewport.height * ASPECT_RATIO;
	viewport.focal_len = 1.0;
	viewport.h_vector = c_vector3(viewport.width, 0, 0);
	viewport.v_vector = c_vector3(0, viewport.height, 0);
	viewport.left_bottom = \
			v_minus(v_minus(v_minus(point, v_divide(viewport.h_vector, 2)), \
			v_divide(viewport.v_vector, 2)), \
			c_vector3(0, 0, viewport.focal_len));
	///////////////////////////
	(void)fov;
	(void)dir_vector;
	///////////////////////////
	return (viewport);
}
