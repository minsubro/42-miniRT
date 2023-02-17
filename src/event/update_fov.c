/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:33 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:46:44 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_fov(int keycode, t_info *info)
{
	if (keycode == KEY_UP && info->scene.camera->fov < 180)
		info->scene.camera->fov++;
	if (keycode == KEY_DOWN && info->scene.camera->fov > 0)
		info->scene.camera->fov--;
}
