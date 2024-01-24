/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:09:13 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:10:19 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	object_move(t_vector3 dir, t_info *info)
{
	t_node	*obj;

	obj = info->scene.figures.head;
	if (obj->type == SPHERE)
		v_plus_(&((t_sphere *)obj->obj)->center, dir);
	else if (obj->type == PLANE)
		v_plus_(&((t_plane *)obj->obj)->point, dir);
	else if (obj->type == CYLINDER)
		v_plus_(&((t_cylinder *)obj->obj)->center, dir);
	else if (obj->type == CONE)
		v_plus_(&((t_cone *)obj->obj)->center, dir);
}
