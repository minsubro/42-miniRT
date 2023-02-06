/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:25:48 by eunson            #+#    #+#             */
/*   Updated: 2023/02/06 11:31:48 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strchr(char *s, char c, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		if (s[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

void	ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	while (src[index] && ((index + 1) <= dstsize))
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize)
		dst[index] = 0;
}

t_nodes	*ft_nodes_add_back(t_nodes **start_node, t_nodes *new_node)
{
	while (*start_node)
		start_node = &((*start_node)->next);
	*start_node = new_node;
	return (*start_node);
}

void	ft_insert_inform(t_nodes **new_node, int fd, char *content, int len)
{
	ft_strcpy((*new_node)->content, content, len);
	(*new_node)->fd = fd;
	(*new_node)->start_idx = 0;
	(*new_node)->end_idx = len;
	(*new_node)->next = 0;
}

void	gnl_exit(char *msg)
{
	printf("Error");
	printf(":: %s\n", msg);
	exit (EXIT_FAILURE);
}
