/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/15 18:27:35 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"

void get_img(void *mlx_ptr, void *win_ptr)
{
	void *player;
	void *collectible;
	void *wall;
	void *empty;
	void *exit;
	int img_width;
	int img_height;

	img_width = 32;
	img_height = 32;

	player = mlx_xpm_file_to_image(mlx_ptr, "./images/player.xpm", &img_width, &img_height);
	collectible = mlx_xpm_file_to_image(mlx_ptr, "./images/collectible.xpm", &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	empty = mlx_xpm_file_to_image(mlx_ptr, "./images/empty.xpm", &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx_ptr, "./images/exit.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, player, 0, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, collectible, 64, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 128, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 192, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 256, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, empty, 192, 64);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, exit, 0, 64);
	(void) win_ptr;
}


// void set_img(t_game game)
// {
// 	int	width;
// 	int	height;

// 	height = 0;
// 	while (height < game.height)
// 	{

// 	}
// }

void	set_game(char	*map_name, t_game *game)
{
	int		fd;
	char	*line;
	
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
		free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_game 	*game;
	// t_map	map;

	// map.row = get_row_length(map);
	// map.column = get_column_length(map[0]);
	if (argc != 2)
		error_exit("Wrong Parameters");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 640, "so_long");
	game = 0;
	set_game(argv[1], game);
	get_img(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);

	return (0);
}