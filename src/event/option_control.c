/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:52 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:47:03 by eunson           ###   ########.fr       */
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
}
