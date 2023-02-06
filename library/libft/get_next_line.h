/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/02/06 11:35:23 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
	char			content[BUFFER_SIZE + 1];
	int				fd;
	int				start_idx;
	int				end_idx;
	struct s_node	*next;
}	t_nodes;

// get_next_line.c file
char	*get_next_line(int fd);

// get_next_line_utils.c file
int		gnl_ft_strchr(char *s, char c, int len);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);
t_nodes	*ft_nodes_add_back(t_nodes **start_node, t_nodes *new_node);
void	ft_insert_inform(t_nodes **new_node, int fd, char *content, int len);
void	gnl_exit(char *msg);

#endif