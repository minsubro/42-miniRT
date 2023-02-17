/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/16 14:50:50 by minsukan         ###   ########.fr       */
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

t_vector3	v_minus_(t_vector3 point)
{
	t_vector3	v1;
	
	v1.x = point.x *= -1;
	v1.y = point.y *= -1;
	v1.z = point.z *= -1;

	return (v1);
}

int	main(int argc, char *argv[])
{
	atexit(leaks);
	check_arguments(argc, argv[1]);
	info = initializer(argv[1]);
	move_scene(&info,  v_minus_(info.scene.camera->point));
	info.scene.camera->point = c_vector3(0, 0, 0);
	draw_scene(&info);
	hook_mlx_event(&info);
//	print_earth(&info); // test
	print_scene(info.scene);
	mlx_loop(info.mlx_info.mlx_ptr);
	return (0);
}

// (완성 - 기능) phong-modeling, shadow
// (완성 - 도형) sphere, plane

// (미완성 - 기능) checkboard, texture
// (미완성 - 도형) cylinder, corn