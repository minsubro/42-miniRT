/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:01 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/14 20:43:42 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_point3 t_point3;
typedef struct s_point3 t_rgb;
typedef struct s_point3 t_vector3;

struct s_point3
{
	double x;
	double y;
	double z;
};

typedef struct s_ambient
{
	double	ratio;
	t_rgb	rgb;
}				t_ambient;

typedef struct s_viewport
{
	t_point3	left_bottom;
	t_vector3	v_vector;
	t_vector3	h_vector;
	double		focal_len;
	double		width;
	double		height;
}			t_viewport;

typedef struct s_camera
{
	t_point3	point;
	t_vector3	dir_vector;
	t_viewport	viewport;
	double		fov;
}				t_camera;

typedef struct s_light
{
	t_point3	point;
	double		brightness_ratio;
	t_rgb		rgb;
}				t_light;

typedef struct s_sphere
{
	t_point3		center;
	t_rgb			rgb;
	double			diameter;
	t_texture_type	texture_type;
}					t_sphere;

typedef struct s_plane
{
	t_point3	point;
	t_vector3	normal_vector;
	t_rgb		rgb;
}				t_plane;

typedef struct s_cylinder
{
	t_point3	center;
	t_vector3	normal_vector;
	double		diameter;
	double		height;
	t_rgb		rgb;
}				t_cylinder;

typedef struct s_cone
{
	t_point3	center;
	t_vector3	normal_vector;
	double		diameter;
	double		height;
	t_rgb		rgb;
}				t_cone;

#endif