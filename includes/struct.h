/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:12:42 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/07 17:10:16 by minsukan         ###   ########.fr       */
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
	t_vector3	dir;
}				t_ray;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}			t_mlx_info;

struct s_list
{
	o_type	type;
	void	*obj;
	t_list	*next;
};


typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_viewport	*view_port;
	t_list		*lights;
	t_list		*figures;
}				t_scene;

typedef struct s_canvas
{
	
	// #define 영역 구분.
}			t_canvas;

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_canvas	canvas;
	t_scene		scene;
}				t_info;

#endif