/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:29 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/13 12:06:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	update_record \
	(t_sphere *sphere, t_ray *ray, t_hit_record *record, t_discriminant data)
{
	double	root;

	root = (-data.b - sqrt(data.value)) / data.a;
	if (check_min_len(data, record, &root) == False)
		return (False);
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

	discriminant = discriminant_sphere(sphere, ray);
	if (discriminant.value < EPSILON)
		return (False);
	return (update_record(sphere, ray, record, discriminant));
}
