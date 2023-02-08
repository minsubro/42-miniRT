/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:12:42 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/08 21:16:59 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "minirt.h"
#include "object.h"

typedef struct s_viewport t_viewport;
typedef struct s_list t_list;

typedef struct s_ray
{
	t_point3	orig;
	t_vector3	dir_vector;
}				t_ray;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}			t_mlx_info;

struct s_list
{
	t_object	type;
	void	*obj;
	t_list	*next;
};

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_list		*lights;
	t_list		*figures;
	t_ray		ray;
}				t_scene;

typedef struct s_image
{
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_image;

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_image		image;
	t_scene		scene;
}				t_info;

#endif