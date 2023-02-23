/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:07:09 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:08:28 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	resize_sphere(t_sphere *sphere, int keycode)
{
	if (keycode == KEY_J)
		sphere->diameter += 1;
	else if (keycode == KEY_L && sphere->diameter > 0)
		sphere->diameter -= 1;
}

static void	resize_cylinder(t_cylinder *cylinder, int keycode)
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

static void	resize_cone(t_cone *cone, int keycode)
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
