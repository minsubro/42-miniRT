/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:20:22 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/07 17:08:23 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_list	*parse_file(char *file_name)
{
	const int 	fd = open(file_name, O_RDONLY);
	t_list		*data_list;
	char		*data;

	data_list = NULL;
	while (1)
	{
		data = get_next_line(fd);
		if (!data) 
			break ;
		if (check_all_white_space(data))		
			free(data);
		else
			list_add_back(&data_list, create_list(data, NONE));
	}
	return	(data_list);
}

void	check_scene(t_scene scene)
{
	if (!scene.ambient || !scene.camera || !scene.lights)
		print_error_with_exit(INVALID_DATA);
}

t_scene	init_scene(char *file_name)
{
	t_scene	scene;
	t_list	*tmp;
	t_list	*data_list;
	char	**splited_data;

	scene.ambient = NULL;
	scene.camera = NULL;
	scene.lights = NULL;
	scene.figures = NULL;
	scene.view_port = init_viewport();
	data_list = parse_file(file_name);
	while (data_list)
	{
		splited_data = ft_split((char *)data_list->obj, ' ');
		object_constructor(&scene, splited_data);
		tmp = data_list;
		data_list = data_list->next;
		free_list(tmp);
		free_dimarr(splited_data);
	}
	check_scene(scene);
	return (scene);
}
