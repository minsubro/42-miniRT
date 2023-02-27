/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:57:00 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/27 15:56:27 by eunson           ###   ########.fr       */
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
# include "mlx.h"
# include "libft.h"

/* extern library */
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

/* src */
/*********************** [calculation] ***********************/

/* [calculation] degree_to_radian.c */
double			degree_to_radian(double degree);

/* [calculation] discriminant.c */
t_discriminant	discriminant_cone(t_cone *cone, t_ray *ray);
t_discriminant	discriminant_cylinder(t_cylinder *cylinder, t_ray *ray);
t_discriminant	discriminant_sphere(t_sphere *sphere, t_ray *ray);

/* [calculation] ray_operation.c */
t_point3		ray_at(t_ray *ray, double t);
t_vector3		get_reflect(t_vector3 v, t_vector3 n);

/* [calculation] set_face_normal.c */
void			set_face_normal(t_ray *ray, t_hit_record *record);

/* [calculation] vec3_operation.c */
double			v_len(t_vector3 v1);
double			v_len_square(t_vector3 v1);
double			vector_value(t_vector3 v1);
void			set_vec3(t_vector3 *vec3, double x, double y, double z);

/* [calculation] vec3_operation2.c */
t_vector3		v_plus(t_vector3 v1, t_vector3 v2);
void			v_plus_(t_vector3 *v1, t_vector3 v2);
t_vector3		v_minus(t_vector3 v1, t_vector3 v2);
t_vector3		v_minus_(t_vector3 point);

/* [calculation] vec3_operation3.c */
t_vector3		v_mult(t_vector3 v1, double s);
t_vector3		v_mult_(t_vector3 v1, t_vector3 v2);
t_vector3		v_divide(t_vector3 v1, double s);

/* [calculation] vec3_operation4.c */
double			v_dot(t_vector3 v1, t_vector3 v2);
t_vector3		v_cross(t_vector3 v1, t_vector3 v2);
t_vector3		v_unit(t_vector3 v1);
t_vector3		v_min(t_vector3 v1, t_vector3 v2);

/*********************** [check] ***********************/

/* [check] check_condition.c*/
t_bool			check_min_len(t_discriminant data, \
					t_hit_record *record, double *len);
t_bool			check_hit_height(t_cylinder *cy, \
					t_point3 p, double *hit_height);
void			check_dir_vector(t_vector3 vec);

/* [check] check_file_condition.c*/
void			check_attribute_cnt(t_object type, int cnt);
void			check_arguments(int argc, char *file_name);
void			check_scene(t_scene scene);
t_bool			check_all_white_space(char *data);
t_bool			check_file_name(char *file_name);

/* [check] check_range.c */
double			check_range(double value, double min, double max);
t_point3		check_object_range(t_point3 value, double min, double max);

/*********************** [constructor] ***********************/

/* [constructor] figure_constructor.c */
void			*c_figures(t_object type, \
					char **data, t_texture_list *texture_list);

/* [constructor] hit_record_constructor.c */
t_hit_record	c_hit_record(void);

/* [constructor] light_constructor.c */
void			*c_light(char **data);
void			*c_spotlight(char **data);

/* [constructor] object_constructor.c */
void			object_constructor(t_scene *scene, \
					char **data, t_texture_list *texture_list);

/* [constructor] ray_constructor.c */
t_ray			c_ray(t_camera *camera, double u, double v);
t_ray			c_ray_direction(t_point3 origin, t_vector3 dir);

/* [constructor] sub_camera.c */
t_camera		sub_camera_init(t_info *info);

/* [constructor] texture_info_constructor.c */
t_texture_info	c_texture_info(char *type, t_texture_list *texture_list);

/* [constructor] vector3_constructor.c */
t_rgb			c_rgb(double x, double y, double z);
t_rgb			c_rgb_by_data(char *data);
t_point3		c_point3(double x, double y, double z);
t_point3		c_point3_by_data(char *data);
t_vector3		c_vector3(double x, double y, double z);

/* [constructor] viewport_constructor.c */
t_viewport		c_viewport(t_camera *camera);
t_viewport		sub_viewport(t_camera *camera);

/*********************** [draw] ***********************/

/* [draw] color.c */
t_rgb			get_color(t_scene *scene);
int				convert_rgb(t_rgb rgb);
t_rgb			int_to_rgb(int pixel);

/* [draw] draw_interface.c */
void			object_control_interface(t_info *info);
void			draw_interface(t_info *info);

/* [draw] draw_scene.c */
void			draw_scene(t_info *info);
void			img_pix_put(t_image *img, int x, int y, int color);

/* [draw] phong_reflection_modeling.c */
t_bool			in_shadow(t_scene *scene, t_vector3 light_dir);
t_rgb			phong_reflection_modeling(t_scene *scene);

/* [draw] point_light.c */
t_rgb			point_light(t_scene *scene, t_light *light);

/* [draw] redraw_scene.c */
void			redraw_scene(t_info *info);

/* [draw] spotlight.c */
t_rgb			spotlight(t_scene *scene, t_spotlight *light);

/* [draw] sub_monitor.c */
void			sub_object_draw(t_info *info);

/*********************** [event] ***********************/

/* [event] camera_control.c */
void			camera_control(int keycode, t_info *info);

/* [event] event_utils.c */
t_vector3		move_value(int keycode);

/* [event] hook_event.c */
int				key_hook(int keycode, t_info *info);
int				mouse_hook(t_info *info);
void			hook_mlx_event(t_info *info);

/* [event] light_control.c */
void			light_control(int keycode, t_info *info);
void			light_move(t_vector3 dir, t_info *info);
void			light_select(int keycode, t_info *info);

/* [event] move_camera.c */
void			move_camera(int keycode, t_info *info);

/* [event] move_object.c */
void			object_move(t_vector3 dir, t_info *info);

/* [event] object_control.c */
void			object_control(int keycode, t_info *info);

/* [event] option_control.c */
void			option_control(int keycode, t_info *info);

/* [event] resize_object.c */
void			object_resize(int keycode, t_info *info);

/* [event] rotate_camera.c */
void			rotate_camera(int keycode, t_info *info);
void			rotation_matrix(t_vector3 axis, \
					double angle, double matrix[3][3]);
t_vector3		apply_rotation_matrix(t_vector3 vector, double matrix[3][3]);

/* [event] rotate_object.c */
void			object_rotate(int keycode, t_info *info);
t_vector3		get_rotate_dir(int keycode);

/* [event] update_fov.c */
void			update_fov(int keycode, t_info *info);

/*********************** [hit] ***********************/
/* [hit] hit_cone.c */
t_bool			hit_cone(t_cone *cone, t_ray *ray, t_hit_record *record);

/* [hit] hit_cylinder.c */
t_bool			hit_cylinder(t_cylinder *cylinder, \
					t_ray *ray, t_hit_record *record);

/* [hit] hit_plane.c */
t_bool			hit_plane(t_plane *plane, t_ray *ray, t_hit_record *record);

/* [hit] hit_sphere.c */
t_bool			hit_sphere(t_sphere	*sphere, t_ray *ray, t_hit_record *record);

/* [hit] hit.c */
t_bool			hit(t_scene *scene, t_ray *ray, t_hit_record *record);
t_bool			sub_hit(t_interface *interface, \
					t_ray *ray, t_hit_record *record);

/* [hit] plane_texture.c */
void			get_plane_uv(t_plane *plane, t_hit_record *record);

/* [hit] sphere_texture.c */
void			get_sphere_uv(t_vector3 normal, t_hit_record *record);
t_rgb			get_texture_color_sphere(\
					t_hit_record *record, t_texture *texture);

/*********************** [initializer] ***********************/

/* [initializer] init_scene.c */
t_scene			init_scene(char *file_name, t_texture_list *texture_list);

/* [initializer] init_scene.c */
void			init_textures(t_texture_list *texture_list, \
					t_mlx_info *mlx_info);

/* [initializer] initializer.c */
t_info			initializer(char *file_name, t_texture_list *texture_list);

/*********************** [utils] ***********************/

/* [utils] array_utils.c */
int				count_array(char **array);

/* [utils] atod.c */
double			atod(char *str);

/* [utils] error.c */
void			print_error_with_exit(char *msg);

/* [utils] free.c */
void			free_dimarr(char **str);
void			list_free(t_list *list);

/* [utils] list.c */
t_node			*create_list(void *value, t_object type);
void			list_add_back(t_list *list, t_node *new);

/* [utils] string_utils.c */
int				ft_strcmp(char *s1, char *s2);

/*********************** [main] ***********************/

/* main.c */
int				main(int argc, char *argv[]);

#endif
