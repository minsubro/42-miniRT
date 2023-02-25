/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:16:59 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/25 17:11:43 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_control(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		move_camera(keycode, info);
	else if (keycode == KEY_DELETE || keycode == KEY_END || \
		keycode == KEY_PD || keycode == KEY_PU || \
		keycode == KEY_INS || keycode == KEY_HOME)
		rotate_camera(keycode, info);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		update_fov(keycode, info);
}
