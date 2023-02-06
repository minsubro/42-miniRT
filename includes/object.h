/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:01 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/06 11:29:01 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef enum e_type
{
	NONE,
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CORN,
}	o_type;

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

typedef struct s_camera
{
	t_point3	view_point;
	t_vector3	vector;
	double		fov;
}				t_camera;

typedef struct s_light
{
	t_point3	point;
	double		ratio;
	t_rgb		rgb;
}				t_light;

typedef struct s_sphere
{
	t_point3	center;
	t_rgb		rgb;
	double		diameter;
}				t_sphere;

typedef struct s_plane
{
	t_point3	point;
	t_vector3	normal_vector;
	t_rgb		rgb;
}				t_plane;

typedef struct s_cylindar
{
	t_point3	point;
	t_vector3	vector;
	double		diameter;
	double		height;
	t_rgb		rgb;
}				t_cylindar;

typedef struct s_cone
{

}				t_cone;

#endif