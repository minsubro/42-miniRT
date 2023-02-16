/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:57:00 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/15 12:55:49 by eunson           ###   ########.fr       */
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

/* library */
# include "libft.h"
# include "mlx.h"

/* extern library */
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

/*********************** [calculation] ***********************/

/* [calculation] discriminant.c */
t_discriminant	discriminant_cone(t_cone *cone, t_ray *ray);
t_discriminant	discriminant_cylinder(t_cylinder *cylinder, t_ray *ray);
t_discriminant	discriminant_sphere(t_sphere *sphere, t_ray *ray);

/* [calculation] ray_operation.c */
t_point3	ray_at(t_ray *ray, double t);
t_vector3	get_reflect(t_vector3 v, t_vector3 n);

/* [calculation] set_face_normal.c */
void	set_face_normal(t_ray *ray, t_hit_record *record);

/* [calculation] vec3_operation.c */
double		v_len(t_vector3 v1);
double		v_len_square(t_vector3 v1);
void		set_vec3(t_vector3 *vec3, double x, double y, double z);

/* [calculation] vec3_operation2.c */
t_vector3	v_plus(t_vector3 v1, t_vector3 v2);
t_vector3	v_minus(t_vector3 v1, t_vector3 v2);
t_vector3	v_mult(t_vector3 v1, double s);
t_vector3	v_mult_(t_vector3 v1, t_vector3 v2);
t_vector3	v_divide(t_vector3 v1, double s);

/* [calculation] vec3_operation3.c */
double		v_dot(t_vector3 v1, t_vector3 v2);
t_vector3	v_cross(t_vector3 v1, t_vector3 v2);
t_vector3	v_unit(t_vector3 v1);
t_vector3	v_min(t_vector3 v1, t_vector3 v2);
void		v_plus_(t_vector3 *v1, t_vector3 v2);

/*********************** [check] ***********************/

/* [check] check_condition.c*/
t_bool		check_min_len(t_discriminant data, t_hit_record *record, double *len);
t_bool		check_hit_height(t_cylinder *cy, t_point3 p, double *hit_height);

/* [check] check_file_condition.c*/
void		check_attribute_cnt(t_object type, int cnt);
void		check_arguments(int argc, char *file_name);
void		check_scene(t_scene scene);
t_bool		check_all_white_space(char *data);
t_bool		check_file_name(char *file_name);

/* [check] check_range.c */
double		check_range(double value, double min, double max);
t_point3	check_object_range(t_point3 value, double min, double max);

/*********************** [constructor] ***********************/

/* [constructor] figure_constructor.c */
void		*c_figures(t_object type, char **data);

/* [constructor] hit_record_constructor.c */
t_hit_record	c_hit_record(void);

/* [constructor] initializer.c */
t_info		initializer(char *file_name);

/* [constructor] object_constructor.c */
void		object_constructor(t_scene *scene, char **data);

/* [constructor] ray_constructor.c */
t_ray		c_ray(t_camera *camera, double u, double v);
t_ray		c_ray_direction(t_point3 origin, t_vector3 dir);

/* [constructor] vector3_constructor.c */
t_rgb		c_rgb(double x, double y, double z);
t_rgb		c_rgb_by_data(char *data);
t_point3	c_point3(double x, double y, double z);
t_point3	c_point3_by_data(char *data);
t_vector3	c_vector3(double x, double y, double z);

/* [constructor] viewport_constructor.c */
t_viewport	c_viewport(t_camera *camera);

/*********************** [draw] ***********************/

/* [draw] color.c */
t_rgb		get_color(t_scene *scene);

/* [draw] draw_scene.c */
void		draw_scene(t_info *info);

/* [draw] hit_cone.c */
t_bool		hit_cone(t_cone *cone, t_ray *ray, t_hit_record *record);

/* [draw] hit_cylinder.c */
t_bool		hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit_record *record);

/* [draw] hit_plane.c */
t_bool		hit_plane(t_plane *plane, t_ray *ray, t_hit_record *record);

/* [draw] hit_sphere.c */
t_bool		hit_sphere(t_sphere	*sphere, t_ray *ray, t_hit_record *record);

/* [draw] hit.c */
t_bool		hit(t_scene *scene, t_ray *ray, t_hit_record *record);

/* [draw] ray.c */
t_bool		in_shadow(t_scene *scene, t_vector3 light_dir);
t_rgb		phong_shading(t_scene *scene, t_light *light);
t_rgb		phong_modeling(t_scene *scene);

/*********************** [event] ***********************/

/* [event] hook_event.c */
int			key_hook(int keycode, t_info *info);
int			mouse_hook(t_info *info);

/*********************** [utils] ***********************/

/* [utils] array_utils.c */
int			count_array(char **array);

/* [utils] atod.c */
double		atod(char *str);

/* [utils] error.c */
void		print_error_with_exit(char *msg);

/* [utils] free.c */
void		free_dimarr(char **str);
void		free_list(t_list *list);

/* [utils] list.c */
t_list		*create_list(void *value, t_object type);
void		list_add_back(t_list **list, t_list *new);

/* [utils] random.c */
double		maths_random_double(double min, double max);

/* [utils] string_utils.c */
int			ft_strcmp(char *s1, char *s2);

/*********************** [main] ***********************/

/* main.c */
int 		main(int argc, char *argv[]);


/* test.c */
void		print_list(t_list *s);
void		print_scene(t_scene scene);
void		print_arr(char **str);

//임시
t_viewport update_viewport(t_camera *camera);

#endif


