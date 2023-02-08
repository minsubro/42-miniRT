/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:33 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/08 21:52:41 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	c_vector3(double x, double y, double z)
{
	t_vector3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_point3	c_point3(double x, double y, double z)
{
	t_point3	point3;
	
	point3.x = x;
	point3.y = y;
	point3.z = z;
	return (point3);
}

t_rgb	c_rgb(double x, double y, double z)
{
	t_rgb	rgb;
	
	rgb.x = x;
	rgb.y = y;
	rgb.z = z;
	return (rgb);
}

void	set_vec3(t_vector3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

double v_len_square(t_vector3 v1)
{
	return (pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
}

double v_len(t_vector3 v1)
{
	return (sqrt(v_len_square(v1))); 
}

t_vector3	v_plus(t_vector3 v1, t_vector3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vector3 v_minus(t_vector3 v1, t_vector3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vector3	v_mult(t_vector3 v1, double s)
{
	v1.x *= s;
	v1.y *= s;
	v1.z *= s;
	return (v1);
}

t_vector3	v_mult_(t_vector3 v1, t_vector3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vector3	v_divide(t_vector3 v1, double s)
{
	v1.x *= 1 / s;
	v1.y *= 1 / s;
	v1.z *= 1 / s;
	return (v1);
}

double      v_dot(t_vector3 v1, t_vector3 v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector3	v_cross(t_vector3 v1, t_vector3 v2)
{
    t_vector3 v3;

    v3.x = v1.y * v2.z - v1.z * v2.y;
    v3.y = v1.z * v2.x - v1.x * v2.z;
    v3.z = v1.x * v2.y - v1.y * v2.x;
    return (v3);
}

t_vector3	v_unit(t_vector3 v1)
{
    double len = v_len(v1);
    if (len == 0)
		print_error_with_exit("Error\n:Devider is 0");
    v1.x /= len;
    v1.y /= len;
    v1.z /= len;
    return (v1);
}

t_vector3	v_min(t_vector3 v1, t_vector3 v2)
{
    if (v1.x > v2.x)
        v1.x = v2.x;
    if (v1.y > v2.y)
        v1.y = v2.y;
    if (v1.z > v2.z)
        v1.z = v2.z;
    return (v1);
}