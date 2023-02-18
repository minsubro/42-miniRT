/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/18 02:11:01 by eunson           ###   ########.fr       */
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
	(void)info;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		move_camera(keycode, info);
	if (keycode == KEY_O || keycode == KEY_P || keycode == KEY_K || keycode == KEY_L || keycode == KEY_N || keycode == KEY_M)
		rotate_camera(keycode, info);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		update_fov(keycode, info);
	if (keycode == KEY_1) // 옵션추가예정!
		option_control(keycode, info);
	redraw_scene(info);
	return (0);
}

int	mouse_hook(t_info *info)
{
	(void)info;
	//mlx_destroy_image(ptr->mlx_ptr, ptr->win_ptr);
	//free_scene();
	exit(EXIT_SUCCESS);
	return (0);
}
