/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:14:39 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 02:23:40 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_node	*create_list(void *value, t_object type)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		print_error_with_exit("malloc fail...");
	new->obj = value;
	new->type = type;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}

void	list_add_back(t_list *list, t_node *new)
{
	if (list->head == NULL)
	{
		list->head = new;
		new->next = list->head;
		new->pre = new->next;
	}
	else
	{
		new->next = list->head;
		new->pre = list->head->pre;
		new->next->pre = new;
		new->pre->next = new;
	}
}
