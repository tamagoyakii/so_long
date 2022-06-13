# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 13:48:07 by jihyukim          #+#    #+#              #
#    Updated: 2022/06/12 21:16:13 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
CC = cc

RM = rm
RM_FLAGS = -rf

MLX_DIR = ./mlx
MLXLIB = $(MLX_DIR)/libmlx.dylib

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c

VPATH = $(shell ls -R)

all : $(NAME)

$(NAME) : $(SRC)
	@make -sC $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXLIB)

clean :
	$(RM) $(RM_FLAGS) $(NAME)

fclean : clean mclean

mclean :
	$(RM) $(RM_FLAGS) $(MLXLIB)
	@make -sC $(MLX_DIR) clean
	$(RM) $(RM_FLAGS) $(LIBFT)
	@make -sC $(LIBFT_DIR) clean

re : fclean
	make

.PHONY : all clean fclean re
