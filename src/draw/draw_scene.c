/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:57:35 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/17 16:17:01 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

static void	set_camera(t_info *info)
{
	move_scene(info, v_minus_(info->scene.camera->point));
	info->scene.camera->point = c_vector3(0,0,0);
}

void	draw_scene(t_info *info)
{
	int		width;
	int		height;
	//int		samples_per_pixel;
	double	u;
	double	v;

	//t_rgb	color;
	set_camera(info);
	height = IMG_HEIGHT - 1;
	while (height >= 0)
	{
		width = 0;
		while (width < IMG_WIDTH)
		{
			// samples_per_pixel = 1;
			// color = c_rgb(0, 0, 0);
			// while (samples_per_pixel >= 0)
			// {
			// 	info->scene.ray = c_ray(info->scene.camera, u, v);
			// 	v_plus_(&color, get_color(&info->scene));
			// 	samples_per_pixel--;
			// }
			// img_pix_put(&info->image, width, IMG_HEIGHT - 1 - height, convert_rgb(color));
			u = (double)width / (IMG_WIDTH - 1);
			v = (double)height / (IMG_HEIGHT - 1);
			info->scene.ray = c_ray(info->scene.camera, u, v);
			img_pix_put(&info->image, width, IMG_HEIGHT - 1 - height, convert_rgb(get_color(&info->scene)));
			width++;
		}
		height--;
	}
	mlx_put_image_to_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr, info->mlx_info.img_ptr, 0, 0);
}
