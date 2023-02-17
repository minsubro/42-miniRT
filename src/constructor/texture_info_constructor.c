/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_info_constructor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:43:00 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:12:44 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	default_texture(t_texture_info *info)
{
	info->type = NORMAL;
	info->texture = NULL;
}

static void	set_texture(t_texture_info *info, char *type, t_texture **texture)
{
	static const char	*type_list[12] = {"normal", "check", "bump", "earth", \
		"jupiter", "mars", "mercury", "neptune", "saturn", "uranus", "venus"};
	int					idx;

	idx = 0;
	while (type_list[idx])
	{
		if (strcmp(type_list[idx], type) == 0)
		{
			info->type = idx;
			info->texture = (t_texture *)texture[idx];
		}
		idx++;
	}
}

t_texture_info	c_texture_info(char *type, t_texture_list *texture_list)
{
	const t_texture		*texture[12] = {
		NULL,
		NULL,
		&(texture_list->bump),
		&(texture_list->earth),
		&(texture_list->jupiter),
		&(texture_list->mars),
		&(texture_list->mercury),
		&(texture_list->neptune),
		&(texture_list->saturn),
		&(texture_list->uranus),
		&(texture_list->venus)
	};
	t_texture_info		info;

	default_texture(&info);
	if (type)
		set_texture(&info, type, (t_texture **)&texture);
	return (info);
}
