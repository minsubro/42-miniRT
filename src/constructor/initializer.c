/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:16:49 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 14:24:25 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_mlx_info	init_mlx_info(void)
{
	t_mlx_info	new;

	new.mlx_ptr = mlx_init();
	new.win_ptr = mlx_new_window(new.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	new.img_ptr = mlx_new_image(new.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	return (new);
}

static t_image	init_image(t_mlx_info mlx)
{
	t_image	image;

	image.addr = mlx_get_data_addr(mlx.img_ptr, &image.bpp, &image.line_len, &image.endian);
	return (image);
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

t_option	init_option() //init_option 파일 따로??
{
	t_option	option;

	option.shadow = True;
	return (option);
}

static t_scene	init_scene(char *file_name)
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
		object_constructor(&scene, splited_data);
		tmp = data_list;
		data_list = data_list->next;
		free_list(tmp);
		free_dimarr(splited_data);
	}
	return (scene);
}

t_info	initializer(char *file_name)
{
	t_info info;

	info.mlx_info = init_mlx_info();
	info.image = init_image(info.mlx_info);
	info.scene = init_scene(file_name);
	return (info);
}
