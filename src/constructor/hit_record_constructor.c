/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_constructor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:55:21 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/10 04:18:05 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_record	c_hit_record(void)
{
	t_hit_record	hit_record;

	hit_record.tmin = EPSILON;
	hit_record.tmax = INFINITY;
	hit_record.front_face = False;
	return (hit_record);
}
//pl  0,0,-4 0,1,0 1,0,0 