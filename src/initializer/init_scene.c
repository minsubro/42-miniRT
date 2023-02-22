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

static t_list	parse_file(char *file_name)
{
	char		*data;
	t_list		data_list;
	const int	fd = open(file_name, O_RDONLY);

	data_list.head = NULL;
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

void	list_free(t_list *list)
{
	t_node *start;
	t_node *tmp;

	start = list->head;
	
	while (1)
	{
		tmp = start;
		start = start->next;
		free(tmp->obj);
		free(tmp);
		if (start == list->head)
			break ;
	}
	
}

t_scene	init_scene(char *file_name, t_texture_list *texture_list)
{
	t_scene	scene;
	t_list	data_list;
	char	**splited_data;

	scene.ambient = NULL;
	scene.camera = NULL;
	scene.lights.head = NULL;
	scene.figures.head = NULL;
	scene.option = init_option();
	data_list = parse_file(file_name);
	t_node *start = data_list.head;
	while (1)
	{
		splited_data = ft_split((char *)start->obj, ' ');
		object_constructor(&scene, splited_data, texture_list);
		start = start->next;
		free_dimarr(splited_data);
		if (start == data_list.head)
			break ;
	}
	list_free(&data_list);
	return (scene);
}
