/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:31:01 by eunson            #+#    #+#             */
/*   Updated: 2023/02/27 15:54:20 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_camera(int keycode, t_info *info)
{
	t_camera		*camera;
	double			mat[3][3];
	const t_vector3	dir = get_rotate_dir(keycode);

	camera = info->scene.camera;
	rotation_matrix(dir, degree_to_radian(15), mat);
	camera->dir_vector = apply_rotation_matrix(camera->dir_vector, mat);
	camera->v_up = apply_rotation_matrix(camera->v_up, mat);
}

void	rotation_matrix(t_vector3 axis, double angle, double matrix[3][3])
{
	const double	c = cos(angle);
	const double	s = sin(angle);
	const double	t = 1.0 - c;

	matrix[0][0] = t * axis.x * axis.x + c;
	matrix[0][1] = t * axis.x * axis.y - s * axis.z;
	matrix[0][2] = t * axis.x * axis.z + s * axis.y;
	matrix[1][0] = t * axis.x * axis.y + s * axis.z;
	matrix[1][1] = t * axis.y * axis.y + c;
	matrix[1][2] = t * axis.y * axis.z - s * axis.x;
	matrix[2][0] = t * axis.x * axis.z - s * axis.y;
	matrix[2][1] = t * axis.y * axis.z + s * axis.x;
	matrix[2][2] = t * axis.z * axis.z + c;
}

t_vector3	apply_rotation_matrix(t_vector3 vector, double matrix[3][3])
{
	t_vector3	result;

	result.x = matrix[0][0] * vector.x + matrix[0][1] * \
		vector.y + matrix[0][2] * vector.z;
	result.y = matrix[1][0] * vector.x + matrix[1][1] * \
		vector.y + matrix[1][2] * vector.z;
	result.z = matrix[2][0] * vector.x + matrix[2][1] * \
		vector.y + matrix[2][2] * vector.z;
	return (result);
}
