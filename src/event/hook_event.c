/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/11 20:33:02 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static int	validated_keycode(int key)
// {
	
// }

void	draw_image(t_info *info) //옮겨야되요!
{
	mlx_clear_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr);
	info->scene.camera->viewport = update_viewport(info->scene.camera);
	draw_scene(info);
}

void	camera_move(int keycode, t_info *info)
{
	if (keycode == KEY_A) // x 축감소
		info->scene.camera->point.x--;
	else if (keycode == KEY_D) // x 축증가
		info->scene.camera->point.x++;
	else if (keycode == KEY_W) // z 축감소
		info->scene.camera->point.z--;
	else if (keycode == KEY_S) // z 축증가
		info->scene.camera->point.z++;
	else if (keycode == KEY_Q) // y 축증가
		info->scene.camera->point.y++;
	else if (keycode == KEY_E) // y 축감소
		info->scene.camera->point.y--;
}

void	update_fov(int keycode, t_info *info)
{
	if (keycode == KEY_UP && info->scene.camera->fov < 180)
		info->scene.camera->fov++;
	if (keycode == KEY_DOWN && info->scene.camera->fov > 0)
		info->scene.camera->fov--;
}

void	option_control(int keycode, t_info *info)
{
	if (keycode == KEY_1)
	{
		if (info->scene.option.shadow == True)
			info->scene.option.shadow = False;
		else
			info->scene.option.shadow = True;
	}
}

void	camera_dir_control(int keycode, t_info *info)
{
	if (keycode == KEY_O) // x 축감소
		info->scene.camera->dir_vector.x -= 0.1;
	else if (keycode == KEY_P) // x 축증가
		info->scene.camera->dir_vector.x += 0.1;
	else if (keycode == KEY_K) // z 축감소
		info->scene.camera->dir_vector.y += 0.1;
	else if (keycode == KEY_L) // z 축증가
		info->scene.camera->dir_vector.y -= 0.1;
	else if (keycode == KEY_N) // y 축증가
		info->scene.camera->dir_vector.z += 0.1;
	else if (keycode == KEY_M) // y 축감소
		info->scene.camera->dir_vector.z -= 0.1;
}

int	key_hook(int keycode, t_info *info)
{
	(void)info;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		camera_move(keycode, info);
	if (keycode == KEY_O || keycode == KEY_P || keycode == KEY_K || keycode == KEY_L || keycode == KEY_N || keycode == KEY_M)
		camera_dir_control(keycode, info);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		update_fov(keycode, info);
	if (keycode == KEY_1) // 옵션추가예정!
		option_control(keycode, info);
	draw_image(info);
	// if (validated_keycode(keycode))
	// {

	// }
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
