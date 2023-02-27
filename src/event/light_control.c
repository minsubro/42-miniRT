/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:12:12 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/27 15:25:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	light_select(int keycode, t_info *info)
{
	t_list	*list;

	list = &info->scene.lights;
	if (keycode == KEY_LEFT)
		list->head = list->head->pre;
	if (keycode == KEY_RIGHT)
		list->head = list->head->next;
}

void	rotate_light(int keycode, t_info *info)
{
	t_spotlight		*light;
	double			mat[3][3];
	const t_vector3	dir = get_rotate_dir(keycode);

	light = (t_spotlight *)info->scene.lights.head->obj;
	rotation_matrix(dir, degree_to_radian(15), mat);
	light->dir = apply_rotation_matrix(light->dir, mat);
}

void	light_move(t_vector3 dir, t_info *info)
{
	t_node	*light;

	light = info->scene.lights.head;
	if (light->type == LIGHT)
		v_plus_(&((t_light *)light->obj)->point, dir);
	else if (light->type == SPOTLIGHT)
		v_plus_(&((t_spotlight *)light->obj)->point, dir);
}

void	light_control(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		light_select(keycode, info);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		light_move(move_value(keycode), info);
	else if (info->scene.lights.head->type == SPOTLIGHT \
			&& (keycode == KEY_DELETE || keycode == KEY_END || \
			keycode == KEY_PD || keycode == KEY_PU || \
			keycode == KEY_INS || keycode == KEY_HOME))
		rotate_light(keycode, info);
}
