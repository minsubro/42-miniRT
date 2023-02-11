/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:29:51 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 16:55:50 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	c_vector3(double x, double y, double z)
{
	t_vector3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_point3	c_point3(double x, double y, double z)
{
	t_point3	point3;

	point3.x = x;
	point3.y = y;
	point3.z = z;
	return (point3);
}

t_rgb	c_rgb(double x, double y, double z)
{
	t_rgb	rgb;

	rgb.x = x;
	rgb.y = y;
	rgb.z = z;
	return (rgb);
}

void	set_vec3(t_vector3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

t_rgb	c_rgb_by_data(char *data)
{
	t_rgb	rgb;
	char	**splitted_data;

	splitted_data = ft_split(data, ',');
	if (count_array(splitted_data) != 3)
		print_error_with_exit(INVALID_ATTR);
	rgb.x = atod(splitted_data[0]) / 255;
	rgb.y = atod(splitted_data[1]) / 255;
	rgb.z = atod(splitted_data[2]) / 255;
	free_dimarr(splitted_data);
	return (rgb);
}

t_point3	c_point3_by_data(char *data)
{
	t_point3	point3;
	char		**splitted_data;

	splitted_data = ft_split(data, ',');
	if (count_array(splitted_data) != 3)
		print_error_with_exit(INVALID_ATTR);
	point3.x = atod(splitted_data[0]);
	point3.y = atod(splitted_data[1]);
	point3.z = atod(splitted_data[2]);
	free_dimarr(splitted_data);
	return (point3);
}
