/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/20 22:05:08 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hook_mlx_event(t_info *info)
{
	mlx_hook(info->mlx_info.win_ptr, HOOK_KEY_EVENT, 0, key_hook, info);
	mlx_hook(info->mlx_info.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, info);
}

void	camera_control(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		move_camera(keycode, info);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
			keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_J || keycode == KEY_K)
		rotate_camera(keycode, info);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		update_fov(keycode, info);
}

void	object_select(int keycode, t_info *info)
{
	t_list	*list;

	list = &info->scene.figures;

	if (keycode == KEY_LEFT)
		list->head = list->head->pre;
	if (keycode == KEY_RIGHT)
		list->head = list->head->next;
}

void	resize_sphere(t_sphere *sphere, int keycode)
{
	if (keycode == KEY_J)
		sphere->diameter += 1;
	else if (keycode == KEY_L && sphere->diameter > 0)
		sphere->diameter -= 1;
}

void	resize_cylinder(t_cylinder *cylinder, int keycode)
{
	if (keycode == KEY_J)
		cylinder->diameter += 1;
	else if (keycode == KEY_L && cylinder->diameter > 1)
		cylinder->diameter -= 1;
	else if (keycode == KEY_I)
		cylinder->height += 1;
	else if (keycode == KEY_K && cylinder->diameter > 1)
		cylinder->height -= 1;
}

void	resize_cone(t_cone *cone, int keycode)
{
	if (keycode == KEY_J)
		cone->diameter += 1;
	else if (keycode == KEY_L && cone->diameter > 0)
		cone->diameter -= 1;
	else if (keycode == KEY_I)
		cone->height += 1;
	else if (keycode == KEY_K && cone->height > 0)
		cone->height -= 1;
}

void	object_resize(int keycode, t_info *info)
{
	t_node	*object;

	object = info->scene.figures.head;
	if (object->type == SPHERE)
		resize_sphere((t_sphere *)object->obj, keycode);
	else if (object->type == CYLINDER)
		resize_cylinder((t_cylinder *)object->obj, keycode);
	else if (object->type == CONE)
		resize_cone((t_cone *)object->obj, keycode);
}

t_vector3	move_value(int keycode)
{
	if (keycode == KEY_D)
		return (c_vector3(1, 0, 0));
	else if (keycode == KEY_A)
		return (c_vector3(-1, 0, 0));
	else if (keycode == KEY_S)
		return (c_vector3(0, 0, 1));
	else if (keycode == KEY_W)
		return (c_vector3(0, 0, -1));
	else if (keycode == KEY_E)
		return (c_vector3(0, -1, 0));
	else if (keycode == KEY_Q)
		return (c_vector3(0, 1, 0));
	return (c_vector3(0, 0, 0));
}

void	object_move(t_vector3 dir, t_info *info)
{
	t_node	*obj;

	obj = info->scene.figures.head;
	if (obj->type == SPHERE)
		v_plus_(&((t_sphere *)obj->obj)->center, dir);
	else if (obj->type == PLANE)
		v_plus_(&((t_plane *)obj->obj)->point, dir);
	else if (obj->type == CYLINDER)
		v_plus_(&((t_cylinder *)obj->obj)->center, dir);
	else if (obj->type == CONE)
		v_plus_(&((t_cone *)obj->obj)->center, dir);
}

void	object_control(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		object_select(keycode, info);
	if (keycode == KEY_I || keycode == KEY_J || keycode == KEY_K || keycode == KEY_L)
		object_resize(keycode, info);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		object_move(move_value(keycode), info);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	if (keycode == KEY_1 || keycode == KEY_2 || \
			keycode == KEY_3 || keycode == KEY_4)
		option_control(keycode, info);
	if (info->scene.option.input_option == CAMERA_CONTROL)
		camera_control(keycode, info);
	if (info->scene.option.input_option == OBJECT_CONTROL)
		object_control(keycode, info);
	redraw_scene(info);
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
