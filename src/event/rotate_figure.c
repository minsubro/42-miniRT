/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:18:04 by eunson            #+#    #+#             */
/*   Updated: 2023/02/18 20:37:20 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	sphere_rotation(t_sphere *sphere, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
// {
// 	sphere->center = c_vector3(vector_value(v_mult_(dir_x, sphere->center)),
// 		vector_value(v_mult_(dir_y, sphere->center)),
// 		vector_value(v_mult_(dir_z, sphere->center)));
// }

// static void	plane_rotation(t_plane *plane, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
// {
// 	plane->point = c_vector3(vector_value(v_mult_(dir_x, plane->point)),
// 		vector_value(v_mult_(dir_y, plane->point)),
// 		vector_value(v_mult_(dir_z, plane->point)));
// 	plane->normal_vector = c_vector3(vector_value(v_mult_(dir_x, plane->normal_vector)),
// 		vector_value(v_mult_(dir_y, plane->normal_vector)),
// 		vector_value(v_mult_(dir_z, plane->normal_vector)));
// }

// static void	cylinder_rotation(t_cylinder *cylinder, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
// {
// 	cylinder->center = c_vector3(vector_value(v_mult_(dir_x, cylinder->center)),
// 		vector_value(v_mult_(dir_y, cylinder->center)),
// 		vector_value(v_mult_(dir_z, cylinder->center)));
// 	cylinder->normal_vector = c_vector3(vector_value(v_mult_(dir_x, cylinder->normal_vector)),
// 		vector_value(v_mult_(dir_y, cylinder->normal_vector)),
// 		vector_value(v_mult_(dir_z, cylinder->normal_vector)));
// }

// static void	cone_rotation(t_cone *cone, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
// {
// 	cone->center = c_vector3(vector_value(v_mult_(dir_x, cone->center)),
// 		vector_value(v_mult_(dir_y, cone->center)),
// 		vector_value(v_mult_(dir_z, cone->center)));
// 	cone->normal_vector = c_vector3(vector_value(v_mult_(dir_x, cone->normal_vector)),
// 		vector_value(v_mult_(dir_y, cone->normal_vector)),
// 		vector_value(v_mult_(dir_z, cone->normal_vector)));
// }

// void	rotate_figure(t_list *obj_list, t_vector3 dir_x, t_vector3 dir_y, t_vector3 dir_z)
// {
// 	while (obj_list)
// 	{
// 		if (obj_list->type == SPHERE)
// 			sphere_rotation((t_sphere *)obj_list->obj, dir_x, dir_y, dir_z);
// 		else if (obj_list->type == PLANE)
// 			plane_rotation((t_plane *)obj_list->obj, dir_x, dir_y, dir_z);
// 		else if (obj_list->type == CYLINDER)
// 			cylinder_rotation((t_cylinder *)obj_list->obj, dir_x, dir_y, dir_z);
// 		else
// 			cone_rotation((t_cone *)obj_list->obj, dir_x, dir_y, dir_z);
// 		obj_list = obj_list->next;
// 	}
// }
