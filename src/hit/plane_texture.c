/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:44:10 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 02:50:58 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_plane_uv(t_plane *plane, t_hit_record *record)
{
	t_vector3	d;
	t_vector3	t;
	t_vector3	b;

	d = v_cross(plane->normal_vector, c_vector3(0, 0, 1));
	if (v_len(d) == 0)
		d = v_cross(plane->normal_vector, c_vector3(0, 1, 0));
	t = v_unit(d);
	b = v_cross(plane->normal_vector, t);
	record->u = v_dot(v_minus(record->p, plane->point), t) / v_dot(t, t);
	record->v = v_dot(v_minus(record->p, plane->point), b) / v_dot(b, b);
}
