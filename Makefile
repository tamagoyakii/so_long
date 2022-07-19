# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 13:48:07 by jihyukim          #+#    #+#              #
#    Updated: 2022/07/18 22:01:22 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 
MLXFLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit

RM = rm
RM_FLAGS = -rf

MLX_DIR = ./mlx
MLXLIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c map_parse.c map_check.c map_print.c operate.c

SRCS_BONUS = bonus/main_bonus.c bonus/map_parse_bonus.c \
						bonus/map_check_bonus.c bonus/map_print_bonus.c \
						bonus/operate_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS) $(LIBFT) $(MLXLIB)
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) -lft $(OBJS) -o $@

$(BONUS) : $(OBJS_BONUS) $(LIBFT) $(MLXLIB)
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) -lft $(OBJS_BONUS) -o $@

$(LIBFT) : 
			$(MAKE) -C $(LIBFT_DIR) all

$(MLXLIB) : 
			$(MAKE) -C $(MLX_DIR) all

clean :
	$(RM) $(RM_FLAGS) $(OBJS) $(OBJS_BONUS)
	@make -sC $(MLX_DIR) clean
	@make -sC $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(RM_FLAGS) $(NAME) $(BONUS)
	$(RM) $(RM_FLAGS) $(MLXLIB)
	$(RM) $(RM_FLAGS) $(LIBFT)

re : fclean
	make

.PHONY : all clean fclean re bonus
