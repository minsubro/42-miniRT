/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_condition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:12:36 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 12:10:43 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_attribute_cnt(t_object type, int cnt)
{
	if (type == AMBIENT_LIGHTNING && cnt != 2)
		print_error_with_exit(INVALID_ATTR);
	else if (type == CAMERA && cnt != 3)
		print_error_with_exit(INVALID_ATTR);
	else if (type == LIGHT && cnt != 3)
		print_error_with_exit(INVALID_ATTR);
	else if ((type == SPHERE || type == PLANE) && (cnt != 3 && cnt != 4))
		print_error_with_exit(INVALID_ATTR);
	else if ((type == CYLINDER || type == CONE) && (cnt != 5 && cnt != 6))
		print_error_with_exit(INVALID_ATTR);
}

void	check_arguments(int argc, char *file_name)
{
	if (argc != 2 || !check_file_name(file_name))
		print_error_with_exit(INVALID_ARGC);
}

void	check_scene(t_scene scene)
{
	if (!scene.ambient || !scene.camera || !scene.lights.head)
		print_error_with_exit(INVALID_DATA);
}

t_bool	check_all_white_space(char *data)
{
	while ((*data >= 9 && *data <= 13) || *data == 32)
		data++;
	if (*data)
		return (False);
	return (True);
}

t_bool	check_file_name(char *file_name)
{
	if (ft_strcmp(ft_strrchr(file_name, '.'), ".rt") == 0)
		return (True);
	return (False);
}
