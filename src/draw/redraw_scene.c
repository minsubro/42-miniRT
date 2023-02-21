/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:01 by eunson            #+#    #+#             */
/*   Updated: 2023/02/21 17:02:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	redraw_scene(t_info *info)
{
	mlx_clear_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr);
	//info->scene.camera->viewport = update_viewport(info->scene.camera);
	///
	info->scene.camera->viewport = test_viewport(info->scene.camera);
	///
	printf("%f %f %f\n", info->scene.camera->point.x, info->scene.camera->point.y, info->scene.camera->point.z);
	draw_scene(info);
}
