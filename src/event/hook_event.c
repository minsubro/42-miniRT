/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/20 22:05:08 by minsukan         ###   ########.fr       */
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
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP || keycode == KEY_DOWN)
		rotate_camera(keycode, info);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
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
