/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:16:11 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/27 15:49:39 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	object_select(int keycode, t_info *info)
{
	t_list	*list;

	list = &info->scene.figures;
	if (keycode == KEY_LEFT)
		list->head = list->head->pre;
	if (keycode == KEY_RIGHT)
		list->head = list->head->next;
}

void	object_control(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		object_select(keycode, info);
	else if (keycode == KEY_I || keycode == KEY_J || \
		keycode == KEY_K || keycode == KEY_L)
		object_resize(keycode, info);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		object_move(move_value(keycode), info);
	else if (keycode == KEY_DELETE || keycode == KEY_END || \
		keycode == KEY_PD || keycode == KEY_PU || \
		keycode == KEY_INS || keycode == KEY_HOME)
		object_rotate(keycode, info);
}
