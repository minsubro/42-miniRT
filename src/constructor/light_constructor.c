/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:35:35 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/26 19:45:10 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*c_light(char **data)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	light->point = c_point3_by_data(data[1]);
	light->brightness_ratio = check_range(atod(data[2]), 0, 1);
	light->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	return (light);
}

void	*c_spotlight(char **data)
{
	t_spotlight	*spotlight;

	spotlight = (t_spotlight *)malloc(sizeof(t_spotlight));
	spotlight->point = c_point3_by_data(data[1]);
	spotlight->dir = \
		check_object_range(c_point3_by_data(data[2]), -1, 1);
	check_dir_vector(spotlight->dir);
	spotlight->brightness_ratio = check_range(atod(data[3]), 0, 1);
	spotlight->rgb = check_object_range(c_rgb_by_data(data[4]), 0, 255);
	return (spotlight);
}