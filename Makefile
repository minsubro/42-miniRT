NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS =  -L $(MLX_DIR) -l mlx -framework OpenGL -framework Appkit

RM = rm -rf

SRCS = main.c									\
\
	   calculation/discriminant.c				\
	   calculation/ray_operation.c				\
	   calculation/set_face_normal.c			\
	   calculation/degree_to_radian.c			\
	   calculation/vec3_operation.c				\
	   calculation/vec3_operation2.c			\
	   calculation/vec3_operation3.c			\
	   calculation/vec3_operation4.c			\
\
	   check/check_condition.c					\
	   check/check_file_condition.c				\
	   check/check_range.c						\
\
	   constructor/figure_constructor.c			\
	   constructor/object_constructor.c			\
	   constructor/ray_construcotr.c			\
	   constructor/texture_info_constructor.c	\
	   constructor/vec3_constructor.c			\
	   constructor/viewport_construcotr.c		\
	   constructor/hit_record_constructor.c		\
	   constructor/sub_camera.c					\
	   constructor/light_constructor.c			\
\
	   draw/color.c								\
	   draw/draw_interface.c					\
	   draw/draw_scene.c						\
	   draw/phong_reflection_modeling.c			\
	   draw/point_light.c						\
	   draw/redraw_scene.c						\
	   draw/spotlight.c							\
	   draw/sub_monitor.c						\
\
	   event/move_camera.c						\
	   event/rotate_camera.c					\
	   event/hook_event.c						\
	   event/option_control.c					\
	   event/update_fov.c						\
	   event/resize_object.c					\
	   event/move_object.c						\
	   event/rotate_object.c					\
	   event/light_control.c					\
	   event/event_utils.c						\
	   event/object_control.c					\
	   event/camera_control.c					\
\
	   hit/hit_cone.c							\
	   hit/hit_cylinder.c						\
	   hit/hit_plane.c							\
	   hit/plane_texture.c						\
	   hit/hit_sphere.c							\
	   hit/sphere_texture.c						\
	   hit/hit.c								\
\
	   initializer/init_scene.c					\
	   initializer/init_textures.c				\
	   initializer/initializer.c				\
\
	   utils/array_utils.c						\
	   utils/atod.c								\
	   utils/error.c							\
	   utils/free.c								\
	   utils/list.c								\
	   utils/string_utils.c						

SRCS_DIR = src/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# LIBFT
LIBFT_DIR = library/libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), libft.a)

# MLX
MLX_DIR = library/minilibx/
MLX_PATH = $(addprefix, $(MLX_DIR), libmlx.a)

INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)

ifdef sanitize
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

%.o : %.c
	@echo "$(YELLOW) *** Generating object files ... *** $(DEFAULT)"
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I$(LIBFT_DIR) -I$(MLX_DIR)

all : $(NAME)
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

$(NAME) : $(OBJS)
	@echo "$(GREEN) *** Compiling miniRT ... *** $(DEFAULT)"
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)
	@echo "$(GREEN) *** Compile Done!! *** $(DEFAULT)"

clean :
	@echo "$(RED) *** Deleting objects ... *** $(DEFAULT)"
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@echo "$(RED) *** Deleeting executable ... *** $(DEFAULT)"
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus : 
	@echo "$(GREEN) *** Bonus Compiling ... *** $(DEFAULT)"
	make all

sanitize :
	make sanitize=1 re

.PHONY : all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m