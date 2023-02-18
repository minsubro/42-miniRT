/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:53:39 by eunson            #+#    #+#             */
/*   Updated: 2023/02/18 20:48:08 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_scene(t_info *info, t_vector3 dir)
{
	move_figure(info->scene.figures, dir);
	move_light(info->scene.lights, dir);
}
