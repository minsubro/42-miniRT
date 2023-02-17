/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:57:35 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/17 13:53:15 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	convert_rgb(t_rgb rgb)
{
	int	color; 

	color = 0;
	color = ((int)(255.0 * rgb.x) << 16) + ((int)(255.0 * rgb.y) << 8) + ((int)(255.0 * rgb.z));
	return (color);
}

void	draw_scene(t_info *info)
{
	int		width;
	int		height;
	//int		samples_per_pixel;
	double	u;
	double	v;

	//t_rgb	color;
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
	printf("camera %f %f %f\n", info->scene.camera->point.x, info->scene.camera->point.y, info->scene.camera->point.z);
	//printf("dir x : %f, y : %f, z : %f\n", info->scene.camera->dir_vector.x, info->scene.camera->dir_vector.y, info->scene.camera->dir_vector.z);
	mlx_put_image_to_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr, info->mlx_info.img_ptr, 0, 0);
}
