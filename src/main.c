/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/20 21:30:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leaks(void)
{
	system("leaks miniRT");
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_texture_list	texture_list;

	//atexit(leaks);
	check_arguments(argc, argv[1]);
	info = initializer(argv[1], &texture_list);
	print_scene(info.scene);
	draw_scene(&info);
	hook_mlx_event(&info);
	mlx_loop(info.mlx_info.mlx_ptr);
	return (0);
}
