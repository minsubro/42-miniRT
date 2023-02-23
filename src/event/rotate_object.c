/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:52 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:06:58 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	get_rotate_dir(int keycode)
{
	if (keycode == KEY_DELETE)
		return (c_vector3(-1, 0, 0));
	if (keycode == KEY_PD)
		return (c_vector3(1, 0, 0));
	if (keycode == KEY_INS)
		return (c_vector3(0, 1, 0));
	if (keycode == KEY_PU)
		return (c_vector3(0, -1, 0));
	if (keycode == KEY_END)
		return (c_vector3(0, 0, 1));
	if (keycode == KEY_HOME)
		return (c_vector3(0, 0, -1));
	return (c_vector3(0, 0, 0));
}

void	object_rotate(int keycode, t_info *info)
{
	double			ma[3][3];
	const t_vector3	dir = get_rotate_dir(keycode);
	t_node			*obj;

	obj = info->scene.figures.head;
	rotation_matrix(dir, degree_to_radian(15), ma);
	if (obj->type == PLANE)
		((t_plane *)obj->obj)->normal_vector = \
			apply_rotation_matrix(((t_plane *)obj->obj)->normal_vector, ma);
	if (obj->type == CYLINDER)
		((t_cylinder *)obj->obj)->normal_vector = \
			apply_rotation_matrix(((t_cylinder *)obj->obj)->normal_vector, ma);
	if (obj->type == CONE)
		((t_cylinder *)obj->obj)->normal_vector = \
			apply_rotation_matrix(((t_cylinder *)obj->obj)->normal_vector, ma);
}
