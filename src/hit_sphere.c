/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:29 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/08 22:32:40 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



t_bool	hit_sphere(t_sphere	*sphere, t_ray *ray)
{
	t_vector3	oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant_value;

	oc = v_minus(ray->orig, sphere->center);
	a = v_len_square(ray->dir_vector);
	half_b = v_dot(oc, ray->dir_vector);
	c = v_len_square(oc) - pow((sphere->diameter / 2), 2);
	discriminant_value = half_b * half_b - a * c;
	if (discriminant_value > 0)
		return (True);
		//return(update_hit_record(sqrt(discriminant_value)));
	return (False);
}

t_bool hit(t_list *object, t_ray *ray) //record 추가
{
	t_list	*start;
	t_bool	ref;
	

	start = object;
	ref = False;
	while (start)
	{
		if (start->type == SPHERE)
			ref = hit_sphere((t_sphere *)start->obj, ray);
		if (ref)
			break;
		start = start->next;
	}
	return ref;
	
	
	// else if (list->type == PLANE)
	// 	return (hit_plane());
	// else if (list->type == CYLINDER)
	// 	return (hit_cylinder());
	// else
	// 	return (hit_corn());
	//return (False);
}
