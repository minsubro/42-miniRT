/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/09 22:55:14 by minsukan         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	t_info		info;

	atexit(leaks);
	check_arguments(argc, argv[1]);
	info = init_info(argv[1]);
	draw_scene(&info);
	hook_mlx_event(&info);
	mlx_loop(info.mlx_info.mlx_ptr);
	return (0);
}

// 1) 그림자
// 2) 다른 도형(평면, 원기둥, 콘)
// 3) 판별식 d. (d/2 말고)
