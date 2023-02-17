/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:53:39 by eunson            #+#    #+#             */
/*   Updated: 2023/02/17 16:53:53 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_scene(t_info *info, t_vector3 dir)
{
	move_figure(info->scene.figures, dir);
	move_light(info->scene.lights, dir);
}
