/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/05 12:45:17 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mlx_info	init_mlx_info(void)
{
	t_mlx_info new;

	new.mlx_ptr = mlx_init();
	new.win_ptr = mlx_new_window(new.mlx_ptr, WIN_WIDTH, WIN_HIEHGT, TITLE);
	new.img_ptr = mlx_new_image(new.mlx_ptr, WIN_WIDTH, WIN_HIEHGT);
	return (new);
}

void	draw_scene(t_mlx_info *mlx_info)
{
	
}

int main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;

	if (argc != 2)
		print_error_with_exit(CHECK_ARGC);
	mlx_info = init_mlx_info();
	
 	// .rt file을 초기화 (문제 있으면 뭐 안에서 종료되겠고 == 파싱)
	init_scene(&mlx_info, argv[1]);
	draw_scene(&mlx_info); 
	// (일단 픽셀 찍고 -> 표면에 색 입히고 -> diffuse인지, specular인지)
	// just color -> diffuse light -> indirect light -> specular light
	//int key_hook(int keycode, void *ptr); 
	//mlx_hook(ptr.win_ptr, HOOK_KEY_EVENT, 0, key_hook, &ptr);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, &ptr);
	//mlx_loop(ptr.mlx_ptr);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, mouse_hook, &ptr);

	// check arguments는 파싱하는 과정에서, 자동으로 하게되어있음.
	
	return (0);
}