/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/06 12:10:08 by minsukan         ###   ########.fr       */
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

int	check_file_name(char *file_name)
{
	if (ft_strcmp(ft_strrchr(file_name, '.'), ".rt") == 0)
		return 1;
	return 0;
}

// void	draw_scene(t_mlx_info *mlx_info)
// {
	
// }

void	check_arguments(int argc, char *file_name)
{
	if (argc != 2 || !check_file_name(file_name)) // check_arguments 로
		print_error_with_exit(CHECK_ARGC);
}

t_info	init_info(char *file_name)
{
	t_info new_info;

	new_info.mlx_info = init_mlx_info();
	new_info.scene = init_scene(file_name);
	return (new_info);
}

int main(int argc, char **argv)
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
	
	// check arguments는 파싱하는 과정에서, 자동으로 하게되어있음.
	return (0);
}