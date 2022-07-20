/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:29:08 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/21 01:33:52 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS	2

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define PX			32
# define IMG_P		"./images/player.xpm"
# define IMG_1		"./images/wall.xpm"
# define IMG_0		"./images/empty.xpm"
# define IMG_BL		"./images/bird_l.xpm"
# define IMG_BR		"./images/bird_r.xpm"
# define IMG_C0		"./images/food.xpm"
# define IMG_C1		"./images/food2.xpm"
# define IMG_C2		"./images/food3.xpm"
# define IMG_C3		"./images/food4.xpm"
# define IMG_E0		"./images/exit.xpm"
# define IMG_E1		"./images/exit2.xpm"
# define IMG_E2		"./images/exit3.xpm"
# define IMG_E3		"./images/exit4.xpm"

typedef struct s_txt{
	void	*img;
}				t_txt;

typedef struct s_img{
	void	*plyr;
	void	*wall;
	void	*emty;
	t_txt	bird[2];
	t_txt	food[4];
	t_txt	exit[4];
}				t_img;

typedef struct s_map{
	char	**map;
	int		row;
	int		col;
	int		p_row;
	int		p_col;
	int		food;
	int		step;
	int		t;
	int		b;
	int		dir;
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
void	game_over(t_map *map_info, t_win *win, int row, int col);
int		close_win(t_win *win);
void	show_win(t_info *info);
int		get_row(char *map_name);
void	get_map(t_map *map, char *map_name, int fd);
void	map_parse(t_info *info, char *map_name);
void	check_ber(char *map_name);
void	check_boundary(t_map *map);
void	check_component(t_map *map);
void	add_count(int *count, t_map *map_info, int x, int y);
void	set_img(void *mlx_ptr, t_img *img);
void	bird_patrol(t_win *win, t_map *map, int row, int col);
void	put_img(t_info *info, int row, int col);
int		print_map(t_info *info);
void	alert(t_win *win, t_map *map_info);
void	map_change(t_map *map_info, int row, int col, char c);
void	move(t_win *win, t_map *map_info, int row, int col);
int		key_press(int keycode, t_info *info);
void	texture_change(t_info *info);
void	bird_dir_change(t_map *map);

#endif