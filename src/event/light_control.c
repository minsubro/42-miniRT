/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:12:12 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:10:58 by minsukan         ###   ########.fr       */
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

void	light_move(t_vector3 dir, t_info *info)
{
	t_node	*light;

	light = info->scene.lights.head;
	v_plus_(&((t_light *)light->obj)->point, dir);
}

void	light_control(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		light_select(keycode, info);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		light_move(move_value(keycode), info);
}
