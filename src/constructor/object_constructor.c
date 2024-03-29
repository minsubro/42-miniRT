/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:34:55 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/27 15:26:06 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*c_ambient(char **data)
{
	t_ambient	*ambient;

	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	ambient->ratio = check_range(atod(data[1]), 0, 1);
	ambient->rgb = check_object_range(c_rgb_by_data(data[2]), 0, 255);
	ambient->rgb = v_mult(ambient->rgb, ambient->ratio);
	return (ambient);
}

static void	*c_camera(char **data)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->point = c_point3_by_data(data[1]);
	camera->dir_vector = \
		check_object_range(c_point3_by_data(data[2]), -1, 1);
	check_dir_vector(camera->dir_vector);
	camera->fov = check_range(atod(data[3]), 0, 180);
	camera->v_up = c_vector3(0, 1, 0);
	if (v_len(v_cross(camera->v_up, camera->dir_vector)) == 0)
		camera->v_up = c_vector3(0, 0, 1);
	camera->viewport = c_viewport(camera);
	return (camera);
}

static t_object	find_type(char *data)
{
	const char	*type[9] = {"A", "C", "L", "SL", "sp", "pl", "cy", "cn", NULL};
	int			idx;

	idx = 0;
	while (type[idx])
	{
		if (ft_strcmp(data, (char *)type[idx]) == 0)
			return (idx + 1);
		idx++;
	}
	print_error_with_exit("invalid type");
	return (0);
}

void	object_constructor(t_scene *scene, char **data, \
	t_texture_list *texture_lst)
{
	t_object	type;

	type = find_type(data[0]);
	check_attribute_cnt(type, count_array(data) - 1);
	if (type == AMBIENT_LIGHTNING)
	{
		if (scene->ambient)
			print_error_with_exit(INVALID_DATA);
		scene->ambient = c_ambient(data);
	}
	else if (type == CAMERA)
	{
		if (scene->camera)
			print_error_with_exit(INVALID_DATA);
		scene->camera = c_camera(data);
	}
	else if (type == LIGHT)
		list_add_back(&scene->lights, create_list(c_light(data), type));
	else if (type == SPOTLIGHT)
		list_add_back(&scene->lights, create_list(c_spotlight(data), type));
	else
		list_add_back(&scene->figures, \
			create_list(c_figures(type, data, texture_lst), type));
}
