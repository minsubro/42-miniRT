/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:33:06 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 15:39:17 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_option	init_option(void)
{
	t_option	option;

	option.shadow = True;
	return (option);
}

static t_list	*parse_file(char *file_name)
{
	char		*data;
	t_list		*data_list;
	const int	fd = open(file_name, O_RDONLY);

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
	return (data_list);
}

t_scene	init_scene(char *file_name, t_texture_list *texture_list)
{
	t_scene	scene;
	t_list	*tmp;
	t_list	*data_list;
	char	**splited_data;

	scene.ambient = NULL;
	scene.camera = NULL;
	scene.lights = NULL;
	scene.figures = NULL;
	scene.option = init_option();
	data_list = parse_file(file_name);
	while (data_list)
	{
		splited_data = ft_split((char *)data_list->obj, ' ');
		object_constructor(&scene, splited_data, texture_list);
		tmp = data_list;
		data_list = data_list->next;
		free_list(tmp);
		free_dimarr(splited_data);
	}
	return (scene);
}
