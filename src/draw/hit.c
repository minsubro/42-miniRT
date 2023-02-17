/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:58:53 by eunson            #+#    #+#             */
/*   Updated: 2023/02/15 12:58:28 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit(t_scene *scene, t_ray *ray, t_hit_record *record)
{
	t_bool		hit_anything;
	t_list		*figure_list;

	hit_anything = False;
	figure_list = scene->figures;
	while (figure_list)
	{
		if (figure_list->type == SPHERE)
		{
			if (hit_sphere((t_sphere *)figure_list->obj, ray, record))
				hit_anything = True;
		}
		else if (figure_list->type == PLANE)
		{
			if (hit_plane((t_plane *)figure_list->obj, ray, record))
				hit_anything = True;
		}
		else if (figure_list->type == CYLINDER)
		{
			if (hit_cylinder((t_cylinder *)figure_list->obj, ray, record))
				hit_anything = True;
		}
		else
		{
			if (hit_cone((t_cone *)figure_list->obj, &scene->ray, record))
				hit_anything = True;	
		}
		figure_list = figure_list->next;
	}
	return (hit_anything);
}
