/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:13:04 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/14 22:15:55 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_texture_type	check_texture_type(char *type)
{
	if (!type)
		return (NORMAL);
	else if (ft_strcmp(type, "earth") == 0)
		return (EARTH);
	else if (ft_strcmp(type, "checker") == 0)
		return (CHECKER);
	else
		return (NORMAL);
}

static void	*c_sphere(char **data)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = c_point3_by_data(data[1]);
	sphere->diameter = atod(data[2]);
	sphere->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	sphere->texture_type = check_texture_type(data[4]);
	return (sphere);
}

static void	*c_plane(char **data)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->point = c_point3_by_data(data[1]);
	plane->normal_vector = check_object_range(c_point3_by_data(data[2]), -1, 1);
	plane->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	return (plane);
}

static void	*c_cylinder(char **data)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	cylinder->center = c_point3_by_data(data[1]);
	cylinder->normal_vector = check_object_range(c_point3_by_data(data[2]), -1, 1);
	cylinder->diameter = atod(data[3]);
	cylinder->height = atod(data[4]);
	cylinder->rgb = check_object_range(c_rgb_by_data(data[5]), 0, 255);
	return (cylinder);
}

// static void	*c_cone(char **data)
// {
	
// }

void	*c_figures(t_object type, char **data)
{
	if (type == SPHERE)
		return (c_sphere(data));
	else if (type == PLANE)
		return (c_plane(data));
	else if (type == CYLINDER)
		return (c_cylinder(data));
	// else
	// 	return (c_cone(data));
	return (NULL);
}
