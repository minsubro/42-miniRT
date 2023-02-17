/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:01 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:46:17 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_image(t_info *info)
{
	mlx_clear_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr);
	info->scene.camera->viewport = update_viewport(info->scene.camera);
	draw_scene(info);
}