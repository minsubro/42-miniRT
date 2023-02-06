/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/06 18:01:19 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char *argv[])
{
	t_info		info;

	check_arguments(argc, argv[1]);
	info = init_info(argv[1]);
	
 	// .rt file을 초기화 (문제 있으면 뭐 안에서 종료되겠고 == 파싱)
	//init_scene(&mlx_info, argv[1]);
	//draw_scene(&mlx_info); 
	// (일단 픽셀 찍고 -> 표면에 색 입히고 -> diffuse인지, specular인지)
	// just color -> diffuse light -> indirect light -> specular light
	//int key_hook(int keycode, void *ptr); 
	//mlx_hook(ptr.win_ptr, HOOK_KEY_EVENT, 0, key_hook, &ptr);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, &ptr);
	//mlx_loop(ptr.mlx_ptr);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, mouse_hook, &ptr);
	return (0);
}