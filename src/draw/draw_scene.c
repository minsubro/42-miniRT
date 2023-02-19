/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:57:35 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/19 16:11:42 by minsukan         ###   ########.fr       */
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
	info->scene.camera->point = c_vector3(0, 0, 0);
}

static void	wait_all_thread(pthread_t	*thread)
{
	int	idx;

	idx = 0;
	while (idx < THREAD_CNT)
	{
		pthread_join(thread[idx], 0);
		idx++;
	}
}

static void	*draw_part_scene(void *input)
{
	double			u;
	double			v;
	int				idx;
	int				width;
	t_thread_data	*data;

	idx = 0;
	data = (t_thread_data *)input;
	while (idx < IMG_HEIGHT / THREAD_CNT)
	{
		width = 0;
		while (width < IMG_WIDTH)
		{
			u = (double)width / (IMG_WIDTH - 1);
			v = (double)data->height / (IMG_HEIGHT - 1);
			data->info.scene.ray = c_ray(data->info.scene.camera, u, v);
			img_pix_put(&data->info.image, width, \
							IMG_HEIGHT - 1 - data->height, \
							convert_rgb(get_color(&data->info.scene)));
			width++;
		}
		idx++;
		data->height -= 1;
	}
	return (0);
}

void	draw_scene(t_info *info)
{
	static pthread_t	thread[THREAD_CNT];
	t_thread_data		thread_data[THREAD_CNT];
	int					idx;

	set_camera(info);
	idx = 0;
	while (idx < THREAD_CNT)
	{
		thread_data[idx].height = \
							(IMG_HEIGHT - 1) - idx * (IMG_HEIGHT / THREAD_CNT);
		thread_data[idx].info = *info;
		pthread_create(&thread[idx], 0, draw_part_scene, &thread_data[idx]);
		idx++;
	}
	wait_all_thread(thread);
	mlx_put_image_to_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr, \
							info->mlx_info.img_ptr, 0, 0);
}
