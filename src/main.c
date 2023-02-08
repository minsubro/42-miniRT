/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/07 16:37:03 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leaks(void)
{
	system("leaks tinyRT");
}

int main(int argc, char *argv[])
{
	t_info		info;

	//atexit(leaks);
	check_arguments(argc, argv[1]);
	info = init_info(argv[1]);
	
 	// .rt file을 초기화 (문제 있으면 뭐 안에서 종료되겠고 == 파싱)
	//init_scene(&mlx_info, argv[1]);
	//draw_scene(&mlx_info); 
	// (일단 픽셀 찍고 -> 표면에 색 입히고 -> diffuse인지, specular인지)
	// just color -> diffuse light -> indirect light -> specular light
	//int key_hook(int keycode, void *ptr); 
	mlx_hook(info.mlx_info.win_ptr, HOOK_KEY_EVENT, 0, key_hook, &info);
	mlx_hook(info.mlx_info.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, &info);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, mouse_hook, &ptr);
	mlx_loop(info.mlx_info.mlx_ptr);
	return (0);
}