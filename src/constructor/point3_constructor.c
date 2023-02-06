/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:20:34 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/06 20:27:45 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	c_point3_by_data(char *data)
{
	t_point3	point3;
	char	**splitted_data;

	splitted_data = ft_split(data, ',');
	for (int i = 0; splitted_data[i]; i++)
		printf("%s\n", splitted_data[i]);
	if (count_array(splitted_data) != 3)
		print_error_with_exit(INVALID_DATA);
	
	point3.x = atod(splitted_data[0]);
	point3.y = atod(splitted_data[1]);
	point3.z = atod(splitted_data[2]);
	free_dimarr(splitted_data);
	return (point3);
}

//c_point3(double x, double y, double z);