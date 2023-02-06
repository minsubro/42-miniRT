/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:14:39 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/06 12:07:01 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*create_list(void *value, o_type type)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		print_error_with_exit("malloc fail...");
	new->obj = value;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	list_add_back(t_list **list, t_list *new)
{
	t_list	*start;

	start = *list;
	if (!start)
		*list = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
}

