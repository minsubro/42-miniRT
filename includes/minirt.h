/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:57:00 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/06 20:23:20 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* includes */
# include "const.h"
# include "error.h"
# include "minirt.h"
# include "object.h"
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

/* src */

/* [constructor] figure_constructor.c */
void		*c_figures(o_type type, char **data);

/* [constructor] object_constructor.c */
void		object_constructor(t_scene *scene, char **data);

/* [constructor] point3_constructor.c */
t_point3	c_point3_by_data(char *data);

/* [utils] array_utils.c */
int			count_array(char **array);

/* [utils] atod.c */
double		atod(char *str);

/* [utils] string_utils.c */
int			ft_strcmp(char *s1, char *s2);

/* check_condition.c */
void		check_attribute_cnt(o_type type, int cnt);
int			check_all_white_space(char *data);
void		check_arguments(int argc, char *file_name);
int			check_file_name(char *file_name);

/* check_range.c */
double		check_range(double value, double min, double max);
t_point3	check_object_range(t_point3 value, double min, double max);

/* error.c */
void		print_error_with_exit(char *msg);

/* free.c */
void		free_dimarr(char **str);
void		free_list(t_list *list);

/* hook.c */

/* init_info.c */
t_info		init_info(char *file_name);

/* init_scene.c */
t_scene		init_scene(char *file_name);

/* list.c */
t_list		*create_list(void *value, o_type type);
void		list_add_back(t_list **list, t_list *new);

/* main.c */
int 		main(int argc, char *argv[]);

/* test.c */
void		print_list(t_list *s);
void		print_scene(t_scene scene);
void		print_arr(char **str);

#endif