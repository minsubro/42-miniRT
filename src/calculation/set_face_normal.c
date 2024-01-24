/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_face_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:07:11 by eunson            #+#    #+#             */
/*   Updated: 2023/02/26 15:03:56 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_ray *ray, t_hit_record *record)
{
	record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	if (record->front_face == False)
		record->normal = v_mult(record->normal, -1);
}
