/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:57:35 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/08 21:21:59 by minsukan         ###   ########.fr       */
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
	int color;

	color = 0;
	color = ((int)(255.999 * rgb.x) << 16) + ((int)(255.999 * rgb.y) << 8) + ((int)(255.999 * rgb.z));
	return (color);
}

void	draw_scene(t_info *info)
{
	int		width;
	int		height;
	double	u;
	double	v;
	//t_ray	ray;

	
	height = IMG_HEIGHT - 1;
	while (height >= 0)
	{
		width = 0;
		while (width < IMG_WIDTH)
		{
			u = (double)width / (IMG_WIDTH - 1);
			v = (double)height / (IMG_HEIGHT - 1);
			info->scene.ray = c_ray(info->scene.camera, u, v);
			img_pix_put(&info->image, width, IMG_HEIGHT - 1 - height, convert_rgb(ray_color(&info->scene)));// << apply_pong();
			width++;
		}
		height--;
	}
	mlx_put_image_to_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr, info->mlx_info.img_ptr, INTERFACE_WIDTH, 0);
	// 퐁 모델 (ambient -> diffuse -> specular)
}

// ray_color()
// {
// 	if (object_color())
// 	{
// 		light_color(); 
// 		// pong_ambient();
// 		// pong_diffuse();
// 		// pong_specular();
// 	}
// 	else
// 		return (255, 255, 255)
// }

//  [next list]
//  1. 평면, 원기둥, 콘(ㅎㅎ)
//  2. 카메라 회전. fov(facial_length를 늘려주면됨.) 도형돌려야되잖아.
// 	rotate struct..? 
//	x_rotate y_rotate z_rotate
//  3. 인터페이스 전에도 한참
//draw_pixel() // 진행하다가?