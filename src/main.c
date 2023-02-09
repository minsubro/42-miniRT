/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/09 14:01:51 by minsukan         ###   ########.fr       */
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


// [방향] : 백그라운드는 하얀색
// 1. 도형 구를 퐁 모델링 적용하는거 (복수 개)
// 2. 색이 있는 빛

// [cpp 01 평가받고 02-ex01 << >> 해결하기] // 저녁 먹고 평가준비.
