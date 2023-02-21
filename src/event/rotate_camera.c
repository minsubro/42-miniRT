/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:31:01 by eunson            #+#    #+#             */
/*   Updated: 2023/02/20 22:03:49 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	camera_rotation_x(t_info *info, double radian)
// {
// 	t_vector3	dir_x;
// 	t_vector3	dir_y;
// 	t_vector3	dir_z;

// 	dir_x = c_vector3(cos(radian), 0, sin(radian));
// 	dir_y = c_vector3(0, 1, 0);
// 	dir_z = c_vector3(-sin(radian), 0, cos(radian));
// 	rotate_figure(info->scene.figures, dir_x, dir_y, dir_z);
// 	rotate_light(info->scene.lights, dir_x, dir_y, dir_z);
// }

// static void	camera_rotation_y(t_info *info, double radian)
// {
// 	t_vector3	dir_x;
// 	t_vector3	dir_y;
// 	t_vector3	dir_z;

// 	dir_x = c_vector3(1, 0, 0);
// 	dir_y = c_vector3(0, cos(radian), -sin(radian));
// 	dir_z = c_vector3(0, sin(radian), cos(radian));
// 	rotate_figure(info->scene.figures, dir_x, dir_y, dir_z);
// 	rotate_light(info->scene.lights, dir_x, dir_y, dir_z);
// }

void	test_camera_dir_x(t_camera *camera, double radian)
{
	t_vector3	dir_x;
	t_vector3	dir_y;
	t_vector3	dir_z;

	dir_x = c_vector3(cos(radian), 0, sin(radian));
	dir_y = c_vector3(0, 1, 0);
	dir_z = c_vector3(-sin(radian), 0, cos(radian));
	
	camera->dir_vector = c_vector3(vector_value(v_mult_(dir_x, camera->dir_vector)),
		vector_value(v_mult_(dir_y, camera->dir_vector)),
		vector_value(v_mult_(dir_z, camera->dir_vector)));
}

void	test_camera_dir_y(t_camera *camera, double radian)
{
	t_vector3	dir_x;
	t_vector3	dir_y;
	t_vector3	dir_z;

	dir_x = c_vector3(1, 0, 0);
	dir_y = c_vector3(0, cos(radian), -sin(radian));
	dir_z = c_vector3(0, sin(radian), cos(radian));
	
	camera->dir_vector = c_vector3(vector_value(v_mult_(dir_x, camera->dir_vector)),
		vector_value(v_mult_(dir_y, camera->dir_vector)),
		vector_value(v_mult_(dir_z, camera->dir_vector)));
}

void	test2_camera_rotation_matrix(t_vector3 axis, double angle, double matrix[3][3])
{
	double c = cos(angle);
	double s = sin(angle);
	double t = 1.0 - c;

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

	result.x = matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z;
    result.y = matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z;
    result.z = matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z;
    
	return (result);
}

void	rotate_camera(int keycode, t_info *info)
{
	// if (keycode == KEY_P)
	// 	camera_rotation_x(info, -degree_to_radian(15));
	// else if (keycode == KEY_O)
	// 	camera_rotation_x(info, degree_to_radian(15));
	// else if (keycode == KEY_K)
	// 	camera_rotation_y(info, degree_to_radian(15));
	// else if (keycode == KEY_L)
	// 	camera_rotation_y(info, -degree_to_radian(15));

	//test1
	// if (keycode == KEY_P)
	// 	test_camera_dir_x(info->scene.camera, -degree_to_radian(15));
	// else if (keycode == KEY_O)
	// 	test_camera_dir_x(info->scene.camera, degree_to_radian(15));
	// else if (keycode == KEY_K)
	// 	test_camera_dir_y(info->scene.camera, degree_to_radian(15));
	// else if (keycode == KEY_L)
	// 	test_camera_dir_y(info->scene.camera, -degree_to_radian(15));

	//test2
	t_camera *camera = info->scene.camera;
	double mat[3][3];
	if (keycode == KEY_UP) // up
	{
		test2_camera_rotation_matrix(c_vector3(1, 0, 0), degree_to_radian(15), mat);
		camera->dir_vector = apply_rotation_matrix(camera->dir_vector, mat);
		camera->v_up = apply_rotation_matrix(camera->v_up, mat);
	}
	else if (keycode == KEY_DOWN) // down
	{
		test2_camera_rotation_matrix(c_vector3(-1, 0, 0), degree_to_radian(15), mat);
		camera->dir_vector = apply_rotation_matrix(camera->dir_vector, mat);
		camera->v_up = apply_rotation_matrix(camera->v_up, mat);
	}
	else if (keycode == KEY_LEFT) // left
	{
		test2_camera_rotation_matrix(c_vector3(0, 1, 0), degree_to_radian(15), mat);
		camera->dir_vector = apply_rotation_matrix(camera->dir_vector, mat);
		camera->v_up = apply_rotation_matrix(camera->v_up, mat);
	}
	else if (keycode == KEY_RIGHT) // right
	{
		test2_camera_rotation_matrix(c_vector3(0, -1, 0), degree_to_radian(15), mat);
		camera->dir_vector = apply_rotation_matrix(camera->dir_vector, mat);
		camera->v_up = apply_rotation_matrix(camera->v_up, mat);
	}
}
