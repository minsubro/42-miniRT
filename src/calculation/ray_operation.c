/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:23:13 by eunson            #+#    #+#             */
/*   Updated: 2023/02/15 11:53:23 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = v_plus(ray->orig, v_mult(ray->dir_vector, t));               
	return (at);
}

t_vector3	get_reflect(t_vector3 v, t_vector3 n)
{
	return (v_minus(v, v_mult(n, v_dot(v, n) * 2)));
}
