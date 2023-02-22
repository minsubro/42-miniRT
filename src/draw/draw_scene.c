/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:57:35 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/22 22:28:37 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// static void	set_camera(t_info *info)
// {
// 	move_scene(info, v_minus_(info->scene.camera->point));
// }

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

t_ray	test_c_ray(t_camera *camera, double u, double v)
{
	double theta = degree_to_radian(camera->fov);
	double half_height = tan(theta / 2.0);
	double half_width = half_height * ASPECT_RATIO;

	t_vector3 w = camera->dir_vector;
	t_vector3 uvec = v_unit(v_cross(camera->v_up, w));
	t_vector3 vvec = v_cross(w, uvec);

	t_vector3 origin = camera->point;
	
	t_vector3 dir = v_unit(v_minus(v_plus(v_mult(uvec, half_width * (2.0 * u - 1.0)), v_mult(vvec, half_height * (1.0f - 2.0f * v))), w));

	t_ray ray;
	ray.orig = origin;
	ray.dir_vector = dir;
	return (ray);
}

t_ray	test2_c_ray(t_camera *camera, int x, int y)
{
	double aspectRatio = (double)IMG_WIDTH / (double)IMG_HEIGHT;
	double px = (2.0 * ((x + 0.5) / camera->viewport.width) - 1.0) * aspectRatio * tan(camera->fov / 2.0);
	double py = (1.0 - 2.0 * ((y + 0.5) / camera->viewport.height)) * tan(camera->fov / 2.0);

	t_vector3 dir = camera->dir_vector;
	t_vector3 right = v_unit(v_cross(dir, camera->v_up));
	t_vector3 upVec = v_unit(v_cross(right, dir));
	
	t_vector3 pixel = v_plus(v_plus(v_plus(camera->point, v_mult(right, px)), v_mult(upVec, py)), camera->dir_vector);
	t_vector3 ray_dir = v_minus(pixel, camera->point);

	t_ray ray;
	ray.dir_vector = camera->dir_vector;
	ray.orig = ray_dir;
	return (ray);
}



t_ray	test3_c_ray(t_camera *camera, double x, double y)
{
	// double theta = degree_to_radian(camera->fov);
	// double half_height = tan(theta / 2.0);
	// double half_width = half_height * ASPECT_RATIO;

	// t_vector3 w = camera->dir_vector;
	// t_vector3 uvec = v_unit(v_cross(camera->v_up, w));
	// t_vector3 vvec = v_cross(w, uvec);

	//t_vector3 origin = camera->point;


	///
	t_viewport viewport;
	
	double theta = degree_to_radian(camera->fov);
	double h = tan(theta / 2);
	viewport.height = IMG_HEIGHT * h;
	viewport.width = viewport.height *  ASPECT_RATIO;

	t_vector3 w = v_unit(camera->dir_vector); 
	t_vector3 u = v_unit(v_cross(camera->v_up, w));
	t_vector3 v = v_cross(w, u);
	
	//t_vector3 origin = camera->point;
	viewport.h_vector = v_mult(u, viewport.width);
	viewport.v_vector = v_mult(v, viewport.height);
	t_vector3	screen_center = v_plus(camera->point, camera->dir_vector);
	viewport.left_bottom = \
		v_minus(v_minus(screen_center, v_mult(viewport.h_vector, (IMG_WIDTH / 2))), v_mult(viewport.v_vector, (IMG_HEIGHT / 2)));
	///
	
	// t_viewport	viewport = camera->viewport;
	// double radian = degree_to_radian(camera->fov / 2);
	// double focal_len = (double)viewport.width / (2.0 * tan(radian));
	
	
	t_ray ray;
	
	// double x_scale = x - (viewport.width / 2);
	// double y_scale = -y + (viewport.height / 2);
	// t_vector3 world = c_vector3(x_scale, y_scale, focal_len);
	
	
	
	ray.orig =  v_plus(v_plus(viewport.left_bottom, v_mult(viewport.h_vector, x)), v_mult(viewport.v_vector, y));
	ray.dir_vector = camera->dir_vector;
	return (ray);
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
			u = (double)width / (double)(IMG_WIDTH - 1);
			v = (double)data->height / (double)(IMG_HEIGHT - 1);
			//data->info.scene.ray = test3_c_ray(data->info.scene.camera, width, data->height);
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
