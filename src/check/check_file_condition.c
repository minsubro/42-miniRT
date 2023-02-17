/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_condition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:12:36 by eunson            #+#    #+#             */
/*   Updated: 2023/02/13 13:09:11 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_attribute_cnt(t_object type, int cnt)
{
	const int	attribute_cnt[7] = {2, 3, 3, 3, 3, 5, 5};

	if (attribute_cnt[type - 1] != cnt)
		print_error_with_exit(INVALID_ATTR);
}

void	check_arguments(int argc, char *file_name)
{
	if (argc != 2 || !check_file_name(file_name))
		print_error_with_exit(INVALID_ARGC);
}

void	check_scene(t_scene scene)
{
	if (!scene.ambient || !scene.camera || !scene.lights)
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
