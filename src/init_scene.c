/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:20:22 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/06 12:09:11 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_all_white_space(char *data)
{
	
	while((*data >= 9 && *data <= 13) || *data == 32)
		data++;
	if (*data)
		return (0);
	return (1);
}

t_list	*parse_file(char *file_name)
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
	
	print_list(data_list);
		

	return	(data_list);
}

t_scene	init_scene(char *file_name)
{
	t_scene	new;
	t_list	*data_list;

	data_list = parse_file(file_name);
	
	new.ambient = 0;
	return (new);
}