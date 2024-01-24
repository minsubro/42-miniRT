/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:11:04 by eunson            #+#    #+#             */
/*   Updated: 2023/02/09 23:26:15 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	if (!s1 || !s2)
		return (1);
	idx = 0;
	while (1)
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		if (s1[idx] == 0 && s2[idx] == 0)
			return (0);
		idx++;
	}
}
