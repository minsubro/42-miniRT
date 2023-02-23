/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:19 by eunson            #+#    #+#             */
/*   Updated: 2023/02/24 03:10:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_camera(int keycode, t_info *info)
{
	t_camera	*camera;

	camera = info->scene.camera;
	if (keycode == KEY_D)
		v_plus_(&camera->point, c_vector3(1, 0, 0));
	else if (keycode == KEY_A)
		v_plus_(&camera->point, c_vector3(-1, 0, 0));
	else if (keycode == KEY_S)
		v_plus_(&camera->point, c_vector3(0, 0, 1));
	else if (keycode == KEY_W)
		v_plus_(&camera->point, c_vector3(0, 0, -1));
	else if (keycode == KEY_E)
		v_plus_(&camera->point, c_vector3(0, -1, 0));
	else if (keycode == KEY_Q)
		v_plus_(&camera->point, c_vector3(0, 1, 0));
}
