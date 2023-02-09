/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:56:16 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/10 01:30:01 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static unsigned short	rand_c(void)
{
	static unsigned short	lfsr = 0xACE1u;
	static unsigned int		bit;

	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return (lfsr = (lfsr >> 1) | (bit << 15));
}

double	maths_random_double(double min, double max)
{
	unsigned int	random;
	double			random_percent;

	(void)min;
	(void)max;

	random = rand_c() << 16 | rand_c();
	random_percent = (random / (0xFFFFFFFF + 1.0));
	return (random_percent);
	//return (min + (max - min) * random_percent);
}