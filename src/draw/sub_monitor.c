/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:52:43 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:11:51 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	get_sub_obj_color(t_interface *interface)
{
	interface->record = c_hit_record();
	if (sub_hit(interface, &interface->ray, &interface->record))
		return (interface->record.albedo);
	else
		return (c_vector3(0, 0, 0));
}

void	sub_object_draw(t_info *info)
{
	int		height;
	int		width;
	double	u;
	double	v;

	info->interface.camera = sub_camera_init(info);
	info->interface.node = info->scene.figures.head;
	height = SUB_IMAGE_HEIGHT - 1;
	while (height >= 0)
	{
		width = 0;
		while (width < SUB_IMAGE_WIDTH)
		{
			u = (double)width / (double)(SUB_IMAGE_WIDTH - 1);
			v = (double)height / (double)(SUB_IMAGE_HEIGHT - 1);
			info->interface.ray = c_ray(&info->interface.camera, u, v);
			img_pix_put(&info->interface.image, width, \
							SUB_IMAGE_HEIGHT - 1 - height, \
							convert_rgb(get_sub_obj_color(&info->interface)));
			width++;
		}
		height--;
	}
}
