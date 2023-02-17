/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:47 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leaks(void)
{
	system("leaks miniRT");
}

void	print_earth(t_info *info)
{
	mlx_put_image_to_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr, info->scene.texture_list.earth.mlx_image, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_texture_list	texture_list;

	atexit(leaks);
	check_arguments(argc, argv[1]);
	info = initializer(argv[1], &texture_list);
	
	move_scene(&info,  v_minus_(info.scene.camera->point));
	info.scene.camera->point = c_vector3(0, 0, 0);
	draw_scene(&info);
	hook_mlx_event(&info);
	//print_earth(&info); // test
	print_scene(info.scene);
	mlx_loop(info.mlx_info.mlx_ptr);
	return (0);
}
