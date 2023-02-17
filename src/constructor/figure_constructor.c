/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:13:04 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/17 11:54:11 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_texture_info	c_texture_info(char *type)
{
	static t_texture	*texture[12] = {
		NULL, 
		NULL, 
		&info.scene.texture_list.bump,
		&info.scene.texture_list.earth,
		&info.scene.texture_list.jupiter,
		&info.scene.texture_list.mars,
		&info.scene.texture_list.mercury,
		&info.scene.texture_list.neptune,
		&info.scene.texture_list.saturn,
		&info.scene.texture_list.uranus,
		&info.scene.texture_list.venus,
	};
	static const char	*type_list[12] = {"normal", "check", "bump", "earth", "jupiter",
		 "mars", "mercury", "neptune", "saturn", "uranus", "venus"};
	int				i;
	t_texture_info	info;

	info.type = NORMAL;
	info.texture = NULL;
	if (!type) {
		return (info);
	}
	i = 0;
	while (type_list[i])
	{
		if (strcmp(type_list[i], type) == 0)
		{
			info.type = i;
			info.texture = texture[i];
		}
		i++;
	}
	return (info);
}

static void	*c_sphere(char **data)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = c_point3_by_data(data[1]);
	sphere->diameter = atod(data[2]);
	sphere->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	sphere->texture_info = c_texture_info(data[4]);
	return (sphere);
}

static void	*c_plane(char **data)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->point = c_point3_by_data(data[1]);
	plane->normal_vector = check_object_range(c_point3_by_data(data[2]), -1, 1);
	plane->rgb = check_object_range(c_rgb_by_data(data[3]), 0, 255);
	plane->texture_info = c_texture_info(data[4]);
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

static void	*c_cone(char **data)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	cone->center = c_point3_by_data(data[1]);
	cone->normal_vector = check_object_range(c_point3_by_data(data[2]), -1, 1);
	cone->diameter = atod(data[3]);
	cone->height = atod(data[4]);
	cone->rgb = check_object_range(c_rgb_by_data(data[5]), 0, 255);
	return (cone);
}

void	*c_figures(t_object type, char **data)
{
	if (type == SPHERE)
		return (c_sphere(data));
	else if (type == PLANE)
		return (c_plane(data));
	else if (type == CYLINDER)
		return (c_cylinder(data));
	else
		return (c_cone(data));
	return (NULL);
}
