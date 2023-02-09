/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:57:00 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/09 11:19:15 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* includes */
# include "const.h"
# include "enum.h"
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
# include <math.h>

/* src */

/* [constructor] figure_constructor.c */
void		*c_figures(t_object type, char **data);

/* [constructor] object_constructor.c */
void		object_constructor(t_scene *scene, char **data);

/* [constructor] point3_constructor.c */
t_point3	c_point3_by_data(char *data);

/* [constructor] viewport_constructor.c */
t_viewport	c_viewport(t_point3	point, t_vector3 dir_vector, double fov);

/* [constructor] ray_constructor.c */
t_ray	c_ray(t_camera *camera, double u, double v);

/* [constructor] hit_record_constructor.c */
t_hit_record	c_hit_record(void);


/* [utils] array_utils.c */
int			count_array(char **array);

/* [utils] atod.c */
double		atod(char *str);

/* [utils] string_utils.c */
int			ft_strcmp(char *s1, char *s2);

/* check_condition.c */
void		check_attribute_cnt(t_object type, int cnt);
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
t_list		*create_list(void *value, t_object type);
void		list_add_back(t_list **list, t_list *new);

/* main.c */
int 		main(int argc, char *argv[]);

/* hook_event.c */
int			key_hook(int keycode, t_info *info);
int			mouse_hook(t_info *info);

/* draw_scene.c */
void		draw_scene(t_info *info);

/* ray.c */

t_point3	ray_at(t_ray *ray, double t);
t_rgb		ray_color(t_scene *scene);

/* hit.c */
t_bool		hit(t_scene *scene, t_hit_record *record);


/* vec3.c */ // 분할 필요
t_vector3	c_vector3(double x, double y, double z);
t_point3	c_point3(double x, double y, double z);
t_rgb		c_rgb(double x, double y, double z);
void		set_vec3(t_vector3 *vec3, double x, double y, double z);
double		v_len_square(t_vector3 v1);
double		v_len(t_vector3 v1);
t_vector3	v_plus(t_vector3 v1, t_vector3 v2);
t_vector3	v_minus(t_vector3 v1, t_vector3 v2);
t_vector3	v_mult(t_vector3 v1, double s);
t_vector3	v_mult_(t_vector3 v1, t_vector3 v2);
t_vector3	v_divide(t_vector3 v1, double s);
double      v_dot(t_vector3 v1, t_vector3 v2);
t_vector3	v_cross(t_vector3 v1, t_vector3 v2);
t_vector3	v_unit(t_vector3 v1);
t_vector3	v_min(t_vector3 v1, t_vector3 v2);

/* test.c */
void		print_list(t_list *s);
void		print_scene(t_scene scene);
void		print_arr(char **str);

#endif