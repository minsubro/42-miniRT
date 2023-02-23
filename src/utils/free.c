/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:03:30 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 02:23:29 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_dimarr(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	list_free(t_list *list)
{
	t_node	*start;
	t_node	*tmp;

	start = list->head;
	while (start)
	{
		tmp = start;
		start = start->next;
		free(tmp->obj);
		free(tmp);
		if (start == list->head)
			break ;
	}
}
