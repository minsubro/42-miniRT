/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:08:40 by eunson            #+#    #+#             */
/*   Updated: 2023/02/08 21:16:59 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_attribute_cnt(t_object type, int cnt)
{
	const int	attribute_cnt[7] = {2, 3, 3, 3, 3, 5, 10};
	if (attribute_cnt[type - 1] != cnt)
		print_error_with_exit(INVALID_DATA);
}

int	check_all_white_space(char *data)
{
	while((*data >= 9 && *data <= 13) || *data == 32)
		data++;
	if (*data)
		return (0);
	return (1);
}

void	check_arguments(int argc, char *file_name)
{
	if (argc != 2 || !check_file_name(file_name))
		print_error_with_exit(CHECK_ARGC);
}

int	check_file_name(char *file_name)
{
	if (ft_strcmp(ft_strrchr(file_name, '.'), ".rt") == 0)
		return 1;
	return 0;
}
