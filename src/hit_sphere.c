/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:29 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/09 22:02:33 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_ray *ray, t_hit_record *record)
{
	record->front_face = v_dot(ray->dir_vector, record->normal) < 0;
	if (record->front_face == False)
		record->normal = v_mult(record->normal, -1);
}

t_discriminant	cal_half_discriminant(t_sphere *sphere, t_ray *ray)
{
	t_vector3	oc;
	t_discriminant	discriminant;
	
	oc = v_minus(ray->orig, sphere->center);
	discriminant.a = v_len_square(ray->dir_vector);
	discriminant.b = v_dot(oc, ray->dir_vector);
	discriminant.c = v_len_square(oc) - pow((sphere->diameter / 2), 2);
	discriminant.value = pow(discriminant.b, 2) - discriminant.a * discriminant.c;
	return (discriminant);
}

t_bool	update_record(t_sphere *sphere, t_ray *ray, t_hit_record *record, t_discriminant data)
{
	double	sqrted;
	double	root;

	sqrted = sqrt(data.value);
	root = (-data.b - sqrted) / data.a;
	if (root < record->tmin || record->tmax < root)
	{
		root = (-data.b + sqrted) / data.a;
		if (root < record->tmin || record->tmax < root)
			return (False);
	}
	record->t = root;
	record->tmax = root;
	record->p = ray_at(ray, root);
	record->albedo = sphere->rgb;
	record->normal = v_unit(v_divide(v_minus(record->p, sphere->center), (sphere->diameter / 2)));
	set_face_normal(ray, record);
	return (True);
}

t_bool	hit_sphere(t_sphere	*sphere, t_ray *ray, t_hit_record *record)
{
	t_discriminant	discriminant;

	discriminant = cal_half_discriminant(sphere, ray);
	if (discriminant.value < 0)
		return (False);
	return (update_record(sphere, ray, record, discriminant));
}

t_bool	hit(t_scene *scene, t_hit_record *record) //record 추가 // double로 변경
{
	t_bool		hit_anything;
	t_list		*figure_list;
	
	hit_anything = False;
	figure_list = scene->figures;
	while (figure_list)
	{
		if (figure_list->type == SPHERE)
			if (hit_sphere((t_sphere *)figure_list->obj, &scene->ray, record))
				hit_anything = True;
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
