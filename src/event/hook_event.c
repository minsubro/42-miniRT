/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/13 21:49:31 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	draw_image(t_info *info) //옮겨야되요!
{
	mlx_clear_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr);
	//info->scene.camera->viewport = update_viewport(info->scene.camera);
	draw_scene(info);
}

void	camera_move(int keycode, t_info *info)
{
	if (keycode == KEY_A) // x 축감소
		info->scene.camera->point.x--;
	else if (keycode == KEY_D) // x 축증가
		info->scene.camera->point.x++;
	else if (keycode == KEY_W) // z 축감소
		info->scene.camera->point.z--;
	else if (keycode == KEY_S) // z 축증가
		info->scene.camera->point.z++;
	else if (keycode == KEY_Q) // y 축증가
		info->scene.camera->point.y++;
	else if (keycode == KEY_E) // y 축감소
		info->scene.camera->point.y--;
}

void	update_fov(int keycode, t_info *info)
{
	if (keycode == KEY_UP && info->scene.camera->fov < 180)
		info->scene.camera->fov++;
	if (keycode == KEY_DOWN && info->scene.camera->fov > 0)
		info->scene.camera->fov--;
}

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

double	vector_value(t_vector3 v1)
{
	return (v1.x + v1.y + v1.z);
}

void	sphere_rotation(t_sphere *sphere, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	sphere->center = c_vector3(vector_value(v_mult_(dir_x, sphere->center)),
		vector_value(v_mult_(dir_y, sphere->center)),
		vector_value(v_mult_(dir_z, sphere->center)));
}

void	plane_rotation(t_plane *plane, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	plane->point = c_vector3(vector_value(v_mult_(dir_x, plane->point)),
		vector_value(v_mult_(dir_y, plane->point)),
		vector_value(v_mult_(dir_z, plane->point)));
	plane->normal_vector = c_vector3(vector_value(v_mult_(dir_x, plane->normal_vector)),
		vector_value(v_mult_(dir_y, plane->normal_vector)),
		vector_value(v_mult_(dir_z, plane->normal_vector)));
}

void	cylinder_rotation(t_cylinder *cylinder, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	cylinder->center = c_vector3(vector_value(v_mult_(dir_x, cylinder->center)),
		vector_value(v_mult_(dir_y, cylinder->center)),
		vector_value(v_mult_(dir_z, cylinder->center)));
}

void	rotation_object(t_list *obj_list, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	while (obj_list)
	{
		if (obj_list->type == SPHERE)
			sphere_rotation((t_sphere *)obj_list->obj, dir_x, dir_y, dir_z);
		else if (obj_list->type == PLANE)
			plane_rotation((t_plane *)obj_list->obj, dir_x, dir_y, dir_z);
		else if (obj_list->type == CYLINDER)
			cylinder_rotation((t_cylinder *)obj_list->obj, dir_x, dir_y, dir_z);
		obj_list = obj_list->next;
	}
}

void	light_rotation(t_light *light, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	light->point = c_vector3(vector_value(v_mult_(dir_x, light->point)),
		vector_value(v_mult_(dir_y, light->point)),
		vector_value(v_mult_(dir_z, light->point)));
}

void	rotation_light(t_list *light, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	while (light)
	{
		light_rotation((t_light *)light->obj, dir_x, dir_y, dir_z);
		light = light->next;
	}
	
}

void	camera_rotation_x(t_info *info, double radian)
{
	t_vector3	dir_x;
	t_vector3	dir_y;
	t_vector3	dir_z;

	dir_x = c_vector3(cos(radian), 0, sin(radian));
	dir_y = c_vector3(0, 1, 0);
	dir_z = c_vector3(0, -sin(radian), cos(radian));
	rotation_object(info->scene.figures, dir_x, dir_y, dir_z);
	rotation_light(info->scene.lights, dir_x, dir_y, dir_z);
}

void	camera_rotation_y(t_info *info, double radian)
{
	t_vector3	dir_x;
	t_vector3	dir_y;
	t_vector3	dir_z;

	dir_x = c_vector3(1, 0, 0);
	dir_y = c_vector3(0, cos(radian), -sin(radian));
	dir_z = c_vector3(0, sin(radian), cos(radian));
	rotation_object(info->scene.figures, dir_x, dir_y, dir_z);
	rotation_light(info->scene.lights, dir_x, dir_y, dir_z);
}

void	camera_rotate(int keycode, t_info *info)
{
	if (keycode == KEY_O) // x 축감소
		camera_rotation_x(info, -degress_to_radians(15));
	else if (keycode == KEY_P) // x 축증가
		camera_rotation_x(info, degress_to_radians(15));
	else if (keycode == KEY_K) // y 축감소
		camera_rotation_y(info, -degress_to_radians(15));
	else if (keycode == KEY_L) // x 축증가
		camera_rotation_y(info, degress_to_radians(15));
}

int	key_hook(int keycode, t_info *info)
{
	(void)info;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		camera_move(keycode, info);
	if (keycode == KEY_O || keycode == KEY_P || keycode == KEY_K || keycode == KEY_L || keycode == KEY_N || keycode == KEY_M)
		camera_rotate(keycode, info);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		update_fov(keycode, info);
	if (keycode == KEY_1) // 옵션추가예정!
		option_control(keycode, info);
	draw_image(info);
	// if (validated_keycode(keycode))
	// {

	// }
	return (0);
}

int	mouse_hook(t_info *info)
{
	(void)info;
	//mlx_destroy_image(ptr->mlx_ptr, ptr->win_ptr);
	//free_scene();
	exit(EXIT_SUCCESS);
	return (0);
}
