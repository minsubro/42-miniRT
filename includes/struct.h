/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:12:42 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/31 15:23:52 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "minirt.h"
#include "object.h"

typedef struct s_obj_list t_obj_list;

typedef struct s_pixel
{

}				t_pixel;

typedef struct s_scene
{
	t_pixel	**map;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_scene;

typedef struct s_ray
{

}				t_ray;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}			t_mlx_info;

struct s_obj_list
{
	e_type		type;
	void		*obj;
	t_obj_list	*next;
};

typedef struct s_scene
{
	t_camera	camera;
	t_obj_list	lights;
	t_obj_list	figures;
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