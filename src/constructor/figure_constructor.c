/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:13:04 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/26 11:04:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*c_sphere(char **data, t_texture_list *texture_list)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = c_point3_by_data(data[1]);
	sphere->diameter = atod(data[2]);
	sphere->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	sphere->texture_info = c_texture_info(data[4], texture_list);
	return (sphere);
}

static void	*c_plane(char **data, t_texture_list *texture_list)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->point = c_point3_by_data(data[1]);
	plane->normal_vector = check_object_range(c_point3_by_data(data[2]), -1, 1);
	check_dir_vector(plane->normal_vector);
	plane->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	plane->texture_info = c_texture_info(data[4], texture_list);
	return (plane);
}

static void	*c_cylinder(char **data, t_texture_list *texture_list)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	cylinder->center = c_point3_by_data(data[1]);
	cylinder->normal_vector = \
		check_object_range(c_point3_by_data(data[2]), -1, 1);
	check_dir_vector(cylinder->normal_vector);
	cylinder->diameter = atod(data[3]);
	cylinder->height = atod(data[4]);
	cylinder->rgb = check_object_range(c_rgb_by_data(data[5]), 0, 255);
	cylinder->texture_info = c_texture_info(data[6], texture_list);
	return (cylinder);
}

static void	*c_cone(char **data)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	cone->center = c_point3_by_data(data[1]);
	cone->normal_vector = check_object_range(c_point3_by_data(data[2]), -1, 1);
	check_dir_vector(cone->normal_vector);
	cone->diameter = atod(data[3]);
	cone->height = atod(data[4]);
	cone->rgb = check_object_range(c_rgb_by_data(data[5]), 0, 255);
	return (cone);
}

void	*c_figures(t_object type, char **data, t_texture_list *texture_list)
{
	if (type == SPHERE)
		return (c_sphere(data, texture_list));
	else if (type == PLANE)
		return (c_plane(data, texture_list));
	else if (type == CYLINDER)
		return (c_cylinder(data, texture_list));
	else
		return (c_cone(data));
	return (NULL);
}
