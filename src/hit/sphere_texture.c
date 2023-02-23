/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:31:51 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 02:49:51 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	get_texture_color_sphere(t_hit_record *record, t_texture *texture)
{
	int				pixel;
	const double	v = 1.0 - record->v;
	const double	x = record->u * (texture->width - 1);
	const double	y = v * (texture->height - 1);

	pixel = *(int *)(texture->image.addr + \
		(int)round(y) * texture->image.line_len + \
		(int)round(x) * (texture->image.bpp / 8));
	return (int_to_rgb(pixel));
}

void	get_sphere_uv(t_vector3 normal, t_hit_record *record)
{
	const double	theta = atan2(normal.x, normal.z);
	const double	radius = v_len(normal);

	record->u = 1.0 - ((theta / (2 * M_PI)) + 0.5);
	record->v = 1.0 - (acos(normal.y / radius)) / M_PI;
}
