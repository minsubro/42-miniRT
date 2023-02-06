/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:19 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/06 17:09:17 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error_with_exit(char *msg)
{
	printf("Error");
	printf(":: %s\n", msg);
	exit (EXIT_FAILURE);
}
