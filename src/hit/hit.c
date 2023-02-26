/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:58:53 by eunson            #+#    #+#             */
/*   Updated: 2023/02/26 14:54:13 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	sub_hit(t_interface *interface, t_ray *ray, t_hit_record *record)
{
	if (interface->node->type == SPHERE)
		return (hit_sphere((t_sphere *)interface->node->obj, ray, record));
	else if (interface->node->type == PLANE)
		return (hit_plane((t_plane *)interface->node->obj, ray, record));
	else if (interface->node->type == CYLINDER)
		return (hit_cylinder((t_cylinder *)interface->node->obj, ray, record));
	else if (interface->node->type == CONE)
		return (hit_cone((t_cone *)interface->node->obj, ray, record));
	return (True);
}

t_bool	hit(t_scene *scene, t_ray *ray, t_hit_record *record)
{
	t_bool		hit_anything;
	t_node		*figure;

	hit_anything = False;
	figure = scene->figures.head;
	while (figure)
	{
		if (figure->type == SPHERE && \
					hit_sphere((t_sphere *)figure->obj, ray, record))
				hit_anything = True;
		else if (figure->type == PLANE && \
					hit_plane((t_plane *)figure->obj, ray, record))
				hit_anything = True;
		else if (figure->type == CYLINDER && \
					hit_cylinder((t_cylinder *)figure->obj, ray, record))
				hit_anything = True;
		else if (figure->type == CONE && \
					hit_cone((t_cone *)figure->obj, &scene->ray, record))
				hit_anything = True;
		figure = figure->next;
		if (figure == scene->figures.head)
			break ;
	}
	return (hit_anything);
}
