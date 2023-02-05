NAME = tinyRT

CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS =  -L mlx -l mlx -framework OpenGL -framework Appkit

RM = rm -rf

# FDF
SRCS = main.c	\
	   error.c	\
	   utils.c
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
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I$(LIBFT_DIR)

all : $(NAME)
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

$(NAME) : $(OBJS)
	@echo "$(GREEN) *** Compiling tinyRT ... *** $(DEFAULT)"
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