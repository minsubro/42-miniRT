/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:16:49 by eunson            #+#    #+#             */
/*   Updated: 2023/02/06 17:33:59 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_mlx_info	init_mlx_info(void)
{
	t_mlx_info new;

	new.mlx_ptr = mlx_init();
	new.win_ptr = mlx_new_window(new.mlx_ptr, WIN_WIDTH, WIN_HIEHGT, TITLE);
	new.img_ptr = mlx_new_image(new.mlx_ptr, WIN_WIDTH, WIN_HIEHGT);
	return (new);
}

t_info	init_info(char *file_name)
{
	t_info new_info;

	new_info.mlx_info = init_mlx_info();
	new_info.scene = init_scene(file_name);
	//test
	return (new_info);
}

