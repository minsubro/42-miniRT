/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:33 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/07 16:22:18 by minsukan         ###   ########.fr       */
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

double vlen_square(t_vector3 v1)
{
	return (pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
}

double vlen(t_vector3 v1)
{
	return (sqrt(vlen_square(v1))); 
}

t_vector3	vplus(t_vector3 v1, t_vector3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vector3 vminus(t_vector3 v1, t_vector3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vector3	vmult(t_vector3 v1, double s)
{
	v1.x *= s;
	v1.y *= s;
	v1.z *= s;
	return (v1);
}

t_vector3	vmult_(t_vector3 v1, t_vector3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vector3	vdivide(t_vector3 v1, double s)
{
	v1.x *= 1 / s;
	v1.y *= 1 / s;
	v1.z *= 1 / s;
	return (v1);
}

double      vdot(t_vector3 v1, t_vector3 v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector3	vcross(t_vector3 v1, t_vector3 v2)
{
    t_vector3 v3;

    v3.x = v1.y * v2.z - v1.z * v2.y;
    v3.y = v1.z * v2.x - v1.x * v2.z;
    v3.z = v1.x * v2.y - v1.y * v2.x;
    return (v3);
}

t_vector3	vunit(t_vector3 v1)
{
    double len = vlen(v1);
    if (len == 0)
		print_error_with_exit("Error\n:Devider is 0");
    v1.x /= len;
    v1.y /= len;
    v1.z /= len;
    return (v1);
}

t_vector3	vmin(t_vector3 v1, t_vector3 v2)
{
    if (v1.x > v2.x)
        v1.x = v2.x;
    if (v1.y > v2.y)
        v1.y = v2.y;
    if (v1.z > v2.z)
        v1.z = v2.z;
    return (v1);
}