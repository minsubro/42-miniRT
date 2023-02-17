/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:31:01 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 21:34:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	camera_rotation_x(t_info *info, double radian)
{
	t_vector3	dir_x;
	t_vector3	dir_y;
	t_vector3	dir_z;

	dir_x = c_vector3(cos(radian), 0, sin(radian));
	dir_y = c_vector3(0, 1, 0);
	dir_z = c_vector3(-sin(radian), 0, cos(radian));
	rotate_figure(info->scene.figures, dir_x, dir_y, dir_z);
	rotate_light(info->scene.lights, dir_x, dir_y, dir_z);
}

static void	camera_rotation_y(t_info *info, double radian)
{
	t_vector3	dir_x;
	t_vector3	dir_y;
	t_vector3	dir_z;

	dir_x = c_vector3(1, 0, 0);
	dir_y = c_vector3(0, cos(radian), -sin(radian));
	dir_z = c_vector3(0, sin(radian), cos(radian));
	rotate_figure(info->scene.figures, dir_x, dir_y, dir_z);
	rotate_light(info->scene.lights, dir_x, dir_y, dir_z);
}

void	rotate_camera(int keycode, t_info *info)
{
	if (keycode == KEY_P)
		camera_rotation_x(info, -degress_to_radians(15));
	else if (keycode == KEY_O)
		camera_rotation_x(info, degress_to_radians(15));
	else if (keycode == KEY_K)
		camera_rotation_y(info, degress_to_radians(15));
	else if (keycode == KEY_L)
		camera_rotation_y(info, -degress_to_radians(15));
}
