/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:29 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/09 17:34:06 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_ray *ray, t_hit_record *record)
{
	record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	if (record->front_face == False)
		record->normal = v_mult(record->normal, -1);
}

t_bool	hit_sphere(t_sphere	*sphere, t_ray *ray, t_hit_record *record)
{
	t_vector3	oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = v_minus(ray->orig, sphere->center);
	a = v_len_square(ray->dir_vector);
	half_b = v_dot(oc, ray->dir_vector);
	c = v_len_square(oc) - pow((sphere->diameter / 2), 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (False);
	
	double	sqrted;
	double	root;
	//////////////
	sqrted = sqrt(discriminant);
	root = (-half_b - sqrted) / a;
	if (root < record->tmin || record->tmax < root)
	{
		root = (-half_b + sqrted) / a;
		if (root < record->tmin || record->tmax < root)
			return (False);
	}
	record->t = root;
	record->p = ray_at(ray, root);
	record->normal = v_divide(v_minus(record->p, sphere->center), (sphere->diameter / 2));
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit(t_scene *scene, t_hit_record *record) //record 추가 // double로 변경
{
	t_list	*figure_list;
	t_bool	hit_anything;
	t_hit_record temp_rec;
	
	temp_rec = *record;
	hit_anything = False;
	figure_list = scene->figures;
	while (figure_list)
	{
		if (figure_list->type == SPHERE)
		{
			if (hit_sphere((t_sphere *)figure_list->obj, &scene->ray, &temp_rec))
			{
				hit_anything = True;
				temp_rec.tmax = temp_rec.t;
				*record = temp_rec;
			} // if문이 생각보다 길어서 hit함수 분할하면 좋을꺼같아여
		}
		figure_list = figure_list->next;
	}
	return (hit_anything);
	
	
	// else if (list->type == PLANE)
	// 	return (hit_plane());
	// else if (list->type == CYLINDER)
	// 	return (hit_cylinder());
	// else
	// 	return (hit_corn());
	//return (False);
}
