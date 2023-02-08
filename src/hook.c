/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/07 16:37:17 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static int	validated_keycode(int key)
// {
	
// }

int	key_hook(int keycode, t_info *info)
{
	(void)info;
	if (keycode == KEY_ESC)
		exit(0);
	// if (validated_keycode(keycode))
	// {

	// }
	return (0);
}

int	mouse_hook(t_info *info)
{
	(void)info;
	//mlx_destroy_image(ptr->mlx_ptr, ptr->win_ptr);
	//free_scene();
	exit(EXIT_SUCCESS);
	return (0);
}
