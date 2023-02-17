/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:43:28 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 21:22:21 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_figure(t_list *object, t_vector3 dir)
{
	while (object)
	{
		if (object->type == SPHERE)
			v_plus_(&(((t_sphere *)(object->obj))->center), dir);
		if (object->type == PLANE)
			v_plus_(&(((t_plane *)(object->obj))->point), dir);
		if (object->type == CYLINDER)
			v_plus_(&(((t_cylinder *)(object->obj))->center), dir);
		if (object->type == CONE)
			v_plus_(&(((t_cone *)(object->obj))->center), dir);
		object = object->next;
	}
}

void	move_light(t_list *light, t_vector3 dir)
{
	while (light)
	{
		v_plus_(&(((t_light *)(light->obj))->point), dir);
		light = light->next;
	}
}
