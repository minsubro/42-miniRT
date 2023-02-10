/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_face_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:07:11 by eunson            #+#    #+#             */
/*   Updated: 2023/02/10 10:35:08 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_ray *ray, t_hit_record *record)
{
	record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	if (record->front_face == False)
		record->normal = v_mult(record->normal, -1);
}
