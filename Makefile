# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 13:48:07 by jihyukim          #+#    #+#              #
#    Updated: 2022/06/11 15:11:09 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
CC = cc

RM = rm
RM_FLAGS = -rf

MLXLIB = libmlx.dylib
MLX_DIR = ./mlx

SRC = main.c

VPATH = $(shell ls -R)

all : $(NAME)

$(NAME) : $(SRC)
	@make -sC $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLXLIB) .
	$(CC) $(CFLAGS) -o $@ $^ $(MLXLIB)

fclean : clean mclean

clean :
	$(RM) $(RM_FLAGS) $(NAME)

mclean :
	$(RM) $(RM_FLAGS) $(MLXLIB)
	@make -sC $(MLX_DIR) clean

re : fclean
	make

.PHONY : all clean fclean re
