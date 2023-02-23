/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:16:49 by eunson            #+#    #+#             */
/*   Updated: 2023/02/24 02:30:47 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_mlx_info	init_mlx_info(void)
{
	t_mlx_info	new;

	new.mlx_ptr = mlx_init();
	new.win_ptr = mlx_new_window(new.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	new.img_ptr = mlx_new_image(new.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	return (new);
}

static t_image	init_image(t_mlx_info mlx)
{
	t_image	image;

	image.addr = mlx_get_data_addr(mlx.img_ptr, &image.bpp, \
									&image.line_len, &image.endian);
	return (image);
}

t_interface	init_interface(t_info *info)
{
	t_interface	interface;

	interface.img_ptr = mlx_new_image(info->mlx_info.mlx_ptr, 300, 300);
	interface.image.addr = mlx_get_data_addr(interface.img_ptr, \
		&interface.image.bpp, &interface.image.line_len, \
		&interface.image.endian);
	return (interface);
}

t_info	initializer(char *file_name, t_texture_list *texture_list)
{
	t_info	info;

	info.mlx_info = init_mlx_info();
	init_textures(texture_list, &info.mlx_info);
	info.image = init_image(info.mlx_info);
	info.scene = init_scene(file_name, texture_list);
	info.interface = init_interface(&info);
	return (info);
}
