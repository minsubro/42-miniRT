/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:57:00 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/06 12:09:00 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* includes*/
# include "const.h"
# include "object.h"
# include "error.h"
# include "struct.h"
# include "utils.h"

/* library */
# include "libft.h"
# include "mlx.h"

/* extern library */
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_scene	init_scene(char *file_name);


// error.c
void	print_error_with_exit(char *msg);

// utils.c
int		ft_strcmp(char *s1, char *s2);

// list.c
t_list	*create_list(void *value, o_type type);
void	list_add_back(t_list **list, t_list *new);




// test.c
void	print_list(t_list *s);

#endif