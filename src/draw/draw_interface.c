/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:40:21 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:16:33 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static const char	*get_mode_to_char(t_input_option option)
{
	if (option == NONE_CONTROL)
		return ("NONE");
	else if (option == CAMERA_CONTROL)
		return ("camera control mode");
	else if (option == OBJECT_CONTROL)
		return ("object control mode");
	else if (option == LIGHT_CONTROL)
		return ("light control mode");
	return ("NONE");
}

static const char	*get_type_to_char(t_object type)
{
	if (type == SPHERE)
		return ("object type : SPHERE");
	else if (type == PLANE)
		return ("object type : PLANE");
	else if (type == CYLINDER)
		return ("object type : CYLINDER");
	else if (type == CONE)
		return ("object type : CONE");
	return ("object type : NONE");
}

void	draw_interface(t_info *info)
{
	const t_mlx_info	*mlx = &info->mlx_info;
	const char			*mode = \
			get_mode_to_char(info->scene.option.input_option);

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 15, 0xffffff, (char *)mode);
	if (info->scene.option.input_option == OBJECT_CONTROL \
			&& info->scene.figures.head)
		object_control_interface(info);
}

void	object_control_interface(t_info *info)
{
	const t_mlx_info	*mlx = &info->mlx_info;
	const char			*type = \
		get_type_to_char(info->scene.figures.head->type);

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, \
		10, 30, 0xffffff, (char *)type);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, \
		10, 60, 0xffffff, "select object");
	sub_object_draw(info);
	mlx_put_image_to_window(info->mlx_info.mlx_ptr, \
		info->mlx_info.win_ptr, info->interface.img_ptr, 10, 80);
}
