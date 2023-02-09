/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_constructor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:55:21 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/09 22:10:43 by minsukan         ###   ########.fr       */
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