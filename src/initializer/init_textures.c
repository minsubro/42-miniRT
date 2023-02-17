/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:44 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 15:40:01 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_texture	get_texture(char *file_name, t_mlx_info *info)
{
	t_texture	texture;

	texture.mlx_image = mlx_xpm_file_to_image(info->mlx_ptr, file_name, \
			&texture.width, &texture.height);
	texture.image.addr = mlx_get_data_addr(texture.mlx_image, \
			&texture.image.bpp, &texture.image.line_len, &texture.image.endian);
	return (texture);
}

void	init_textures(t_texture_list *texture_list, t_mlx_info *mlx_info)
{
	texture_list->bump = get_texture("./texture/bump.xpm", mlx_info);
	texture_list->earth = get_texture("./texture/earth.xpm", mlx_info);
	texture_list->jupiter = get_texture("./texture/jupiter.xpm", mlx_info);
	texture_list->mars = get_texture("./texture/mars.xpm", mlx_info);
	texture_list->mercury = get_texture("./texture/mercury.xpm", mlx_info);
	texture_list->neptune = get_texture("./texture/neptune.xpm", mlx_info);
	texture_list->saturn = get_texture("./texture/saturn.xpm", mlx_info);
	texture_list->uranus = get_texture("./texture/uranus.xpm", mlx_info);
	texture_list->venus = get_texture("./texture/venus.xpm", mlx_info);
}
