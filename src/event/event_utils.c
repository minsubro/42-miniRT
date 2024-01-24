/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:14:26 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 02:14:32 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	move_value(int keycode)
{
	if (keycode == KEY_D)
		return (c_vector3(1, 0, 0));
	else if (keycode == KEY_A)
		return (c_vector3(-1, 0, 0));
	else if (keycode == KEY_S)
		return (c_vector3(0, 0, 1));
	else if (keycode == KEY_W)
		return (c_vector3(0, 0, -1));
	else if (keycode == KEY_E)
		return (c_vector3(0, -1, 0));
	else if (keycode == KEY_Q)
		return (c_vector3(0, 1, 0));
	return (c_vector3(0, 0, 0));
}
