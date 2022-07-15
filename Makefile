# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 13:48:07 by jihyukim          #+#    #+#              #
#    Updated: 2022/07/15 18:33:43 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit

RM = rm
RM_FLAGS = -rf

MLX_DIR = ./mlx
MLXLIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c utils.c

OBJS = $(SRCS:.c=.o)

VPATH = $(shell ls -R)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLXLIB)
			cp $(MLXLIB) ./
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) -lft $(OBJS) -o $@

$(LIBFT) : 
			$(MAKE) -C $(LIBFT_DIR) all

$(MLXLIB) : 
			$(MAKE) -C $(MLX_DIR) all

clean :
	$(RM) $(RM_FLAGS) $(OBJS)

fclean : clean mclean
	$(RM) $(RM_FLAGS) $(NAME)
	$(RM) $(RM_FLAGS) $(MLXLIB)
	$(RM) $(RM_FLAGS) $(LIBFT)

mclean :
	@make -sC $(MLX_DIR) clean
	@make -sC $(LIBFT_DIR) clean

re : fclean
	make

.PHONY : all clean fclean mclean re
