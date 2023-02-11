/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/11 16:44:09 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leaks(void)
{
	system("leaks miniRT");
}

void	hook_mlx_event(t_info *info)
{
	mlx_hook(info->mlx_info.win_ptr, HOOK_KEY_EVENT, 0, key_hook, info);
	mlx_hook(info->mlx_info.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, info);
}

int	main(int argc, char *argv[])
{
	t_info		info;

	atexit(leaks);
	check_arguments(argc, argv[1]);
	info = initializer(argv[1]);
	draw_scene(&info);
	hook_mlx_event(&info);
	print_scene(info.scene);
	mlx_loop(info.mlx_info.mlx_ptr);
	return (0);
}

// (완성 - 기능) phong-modeling, shadow
// (완성 - 도형) sphere, plane

// (미완성 - 기능) checkboard, texture
// (미완성 - 도형) cylinder, corn