/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/25 19:21:28 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hook_mlx_event(t_info *info)
{
	mlx_hook(info->mlx_info.win_ptr, HOOK_KEY_EVENT, 0, key_hook, info);
	mlx_hook(info->mlx_info.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, info);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	if (keycode == KEY_1 || keycode == KEY_2 || \
			keycode == KEY_3 || keycode == KEY_4)
		option_control(keycode, info);
	if (info->scene.option.input_option == CAMERA_CONTROL)
		camera_control(keycode, info);
	if (info->scene.option.input_option == OBJECT_CONTROL \
		&& info->scene.figures.head)
		object_control(keycode, info);
	if (info->scene.option.input_option == LIGHT_CONTROL)
		light_control(keycode, info);
	redraw_scene(info);
	return (0);
}

int	mouse_hook(t_info *info)
{
	(void)info;
	exit(EXIT_SUCCESS);
	return (0);
}
