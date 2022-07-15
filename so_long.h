/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:29:08 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/15 18:03:25 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_map{
	int	row;
	int	column;
}				t_map;
typedef struct s_param{
	int	x;
	int	y;
}				t_param;
typedef struct s_game{
	int		width;
	int		height;
	char	*str_line;
}				t_game;

void	error_exit(char *str);
char	*ft_strdup_without_newline(const char *s1);
void	set_game(char	*map_name, t_game *game);
void get_img(void *mlx_ptr, void *win_ptr);

#endif