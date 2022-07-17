/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:29:08 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/17 13:24:37 by jihyukim         ###   ########.fr       */
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

# define PX				32
# define IMG_P			"./images/player.xpm"
# define IMG_C			"./images/collectible.xpm"
# define IMG_1			"./images/wall.xpm"
# define IMG_0			"./images/empty.xpm"
# define IMG_E			"./images/exit.xpm"

typedef struct s_img{
	void	*plyr;
	void	*coll;
	void	*wall;
	void	*emty;
	void	*exit;
}				t_img;
typedef struct s_map{
	char	**map;
	int		row;
	int		column;
	int		player_x;
	int		player_y;
	int		collectible;
	int		step;
}				t_map;
typedef struct s_win{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;
typedef struct s_info{
	t_map	map;
	t_win	win;
	t_img	img;
}				t_info;

int		get_row(t_map *map, char *map_name);
void	get_map(t_map *map, char *map_name, int fd);
void	map_parse(t_info *info, char *map_name);
void	error_exit(char *str);
void	check_ber(char *map_name);
void	check_boundary(t_map *map);
void	get_object_count(int *count, t_map *map);
void	get_player_position(int *count, t_map *map, int x, int y);
void	check_component(t_map *map);
void	set_img(void *mlx_ptr, t_img *img);
void	put_img(char c, t_win *win, t_img *img, int x, int y);
void	print_map(t_map *map_info, t_win *win, t_img *img);
void	show_window(t_info *info);

#endif