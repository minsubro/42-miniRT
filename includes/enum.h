/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:13:11 by minsukan          #+#    #+#             */
/*   Updated: 2023/02/24 03:35:00 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_type
{
	NONE,
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
}	t_object;

typedef enum e_texture_type
{
	NORMAL,
	CHECK,
	BUMP,
	EARTH,
	JUPITER,
	MARS,
	MERCURY,
	NEPTUNE,
	SATURN,
	URANUS,
	VENUS
}	t_texture_type;

typedef enum e_input_option
{
	NONE_CONTROL,
	CAMERA_CONTROL,
	OBJECT_CONTROL,
	LIGHT_CONTROL
}	t_input_option;

typedef enum e_key {
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_H = 4,
	KEY_G = 5,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 22,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_O = 31,
	KEY_I = 34,
	KEY_P = 35,
	KEY_L = 37,
	KEY_J = 38,
	KEY_K = 40,
	KEY_N = 45,
	KEY_M = 46,
	KEY_ESC = 53,
	KEY_HOME = 115,
	KEY_PU = 116,
	KEY_DELETE = 117,
	KEY_END = 119,
	KEY_PD = 121,
	KEY_INS = 279,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
}	t_keycode;

typedef enum e_bool {
	True = 1,
	False = 0,
}	t_bool;

#endif