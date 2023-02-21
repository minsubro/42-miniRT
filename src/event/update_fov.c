/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:33 by eunson            #+#    #+#             */
/*   Updated: 2023/02/20 22:05:19 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_fov(int keycode, t_info *info)
{
	if (keycode == KEY_PLUS && info->scene.camera->fov < 180)
		info->scene.camera->fov++;
	if (keycode == KEY_MINUS && info->scene.camera->fov > 0)
		info->scene.camera->fov--;
}
