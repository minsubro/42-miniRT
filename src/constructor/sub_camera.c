/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:44:21 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:31:54 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector3	get_obj_point(t_node *obj)
{
	if (obj->type == SPHERE)
		return (v_minus(((t_sphere *) obj->obj)->center, \
			c_vector3(0, 0, -(((t_sphere *)obj->obj)->diameter)*1.5)));
	else if (obj->type == PLANE)
		return (v_minus(((t_plane *)obj->obj)->point, c_vector3(5, -5, -5)));
	else if (obj->type == CYLINDER)
		return (v_minus(((t_cylinder *)obj->obj)->center, \
			c_vector3(0, 0, -(((t_cylinder *)obj->obj)->diameter)*1.5)));
	else if (obj->type == CONE)
		return (v_minus(((t_cone *) obj->obj)->center, \
			c_vector3(0, 0, -(((t_cylinder *)obj->obj)->diameter))));
	return (c_vector3(0, 0, 0));
}

t_camera	sub_camera_init(t_info *info)
{
	t_camera	camera;

	camera.dir_vector = c_vector3(0, 0, -1);
	camera.fov = 60;
	camera.point = get_obj_point(info->scene.figures.head);
	camera.viewport = sub_viewport(&camera);
	return (camera);
}
