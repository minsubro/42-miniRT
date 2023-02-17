/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/17 12:19:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	draw_image(t_info *info) //옮겨야되요!
{
	mlx_clear_window(info->mlx_info.mlx_ptr, info->mlx_info.win_ptr);
	info->scene.camera->viewport = update_viewport(info->scene.camera);
	draw_scene(info);
}

void	hook_mlx_event(t_info *info)
{
	mlx_hook(info->mlx_info.win_ptr, HOOK_KEY_EVENT, 0, key_hook, info);
	mlx_hook(info->mlx_info.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, info);
}

void	move_object(t_list *object, t_vector3 dir)
{
	while (object)
	{
		if (object->type == SPHERE)
			v_plus_(&(((t_sphere *)(object->obj))->center), dir);
		if (object->type == PLANE)
			v_plus_(&(((t_plane *)(object->obj))->point), dir);
		if (object->type == CYLINDER)
			v_plus_(&(((t_cylinder *)(object->obj))->center), dir);
		if (object->type == CONE)
			v_plus_(&(((t_cone *)(object->obj))->center), dir);
		object = object->next;
	}
}

void	move_light(t_list *light, t_vector3 dir)
{
	while (light)
	{
		v_plus_(&(((t_light *)(light->obj))->point), dir);
		light = light->next;
	}
}

void	move_scene(t_info *info, t_vector3 dir)
{
	move_object(info->scene.figures, dir);
	move_light(info->scene.lights, dir);
}

void	camera_move(int keycode, t_info *info)
{
	if (keycode == KEY_A) // x 축감소
		move_scene(info, c_vector3(1, 0, 0));
	else if (keycode == KEY_D) // x 축증가
		move_scene(info, c_vector3(-1, 0, 0));
	else if (keycode == KEY_W) // z 축감소
		move_scene(info, c_vector3(0, 0, -1));
	else if (keycode == KEY_S) // z 축증가
		move_scene(info, c_vector3(0, 0, 1));
	else if (keycode == KEY_Q) // y 축증가
		move_scene(info, c_vector3(0, 1, 0));
	else if (keycode == KEY_E) // y 축감소
		move_scene(info, c_vector3(0, -1, 0));
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

void	cone_rotation(t_cone *cone, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
{
	cone->center = c_vector3(vector_value(v_mult_(dir_x, cone->center)),
		vector_value(v_mult_(dir_y, cone->center)),
		vector_value(v_mult_(dir_z, cone->center)));
	cone->normal_vector = c_vector3(vector_value(v_mult_(dir_x, cone->normal_vector)),
		vector_value(v_mult_(dir_y, cone->normal_vector)),
		vector_value(v_mult_(dir_z, cone->normal_vector)));
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
		else
			cone_rotation((t_cone *)obj_list->obj, dir_x, dir_y, dir_z);
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
	dir_z = c_vector3(-sin(radian), 0, cos(radian));
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
	if (keycode == KEY_P) // right
		camera_rotation_x(info, -degress_to_radians(15));
	else if (keycode == KEY_O) // left
		camera_rotation_x(info, degress_to_radians(15));
	else if (keycode == KEY_K) // up
		camera_rotation_y(info, degress_to_radians(15));
	else if (keycode == KEY_L) // down
		camera_rotation_y(info, -degress_to_radians(15));
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
