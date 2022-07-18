/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:29:08 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/18 18:50:40 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS			2

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
	void	*food;
	void	*wall;
	void	*emty;
	void	*exit;
}				t_img;
typedef struct s_map{
	char	**map;
	int		row;
	int		col;
	int		p_row;
	int		p_col;
	int		food;
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

void	error_exit(char *str);
void	show_win(t_info *info);
int		get_row(char *map_name);
void	get_map(t_map *map, char *map_name, int fd);
void	map_parse(t_info *info, char *map_name);
void	check_ber(char *map_name);
void	check_boundary(t_map *map);
void	check_component(t_map *map);
void	add_count(int *count, t_map *map_info, int x, int y);
void	set_img(void *mlx_ptr, t_img *img);
void	put_img(t_info *info, int row, int col);
int		print_map(t_info *info);
void	alert(t_win *win, t_map *map_info);
void	map_change(t_map *map_info, int row, int col);
void	move(t_win *win, t_map *map_info, int row, int col);
int		key_press(int keycode, t_info *info);
int		close_win(t_win *win);

#endif