/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:52 by eunson            #+#    #+#             */
/*   Updated: 2023/02/24 04:20:09 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	option_control(int keycode, t_info *info)
{
	if (keycode == KEY_1)
	{
		if (info->scene.option.shadow == True)
			info->scene.option.shadow = False;
		else
			info->scene.option.shadow = True;
	}
	else if (keycode == KEY_2)
		info->scene.option.input_option = CAMERA_CONTROL;
	else if (keycode == KEY_3)
		info->scene.option.input_option = OBJECT_CONTROL;
	else if (keycode == KEY_4)
		info->scene.option.input_option = LIGHT_CONTROL;
}
