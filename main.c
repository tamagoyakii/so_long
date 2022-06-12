/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/06/12 18:59:19 by jihyukim         ###   ########.fr       */
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

	img_width = 64;
	img_height = 64;

	player = mlx_xpm_file_to_image(mlx_ptr, "./images/player.xpm", &img_width, &img_height);
	collectible = mlx_xpm_file_to_image(mlx_ptr, "./images/collectible.xpm", &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	empty = mlx_xpm_file_to_image(mlx_ptr, "./images/empty.xpm", &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx_ptr, "./images/exit.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, player, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, collectible, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 128, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 192, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 256, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, empty, 192, 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, exit, 0, 64);
}

// void map_read(char *filename, t_game *game)
// {

// }

// void set_img(t_game game)
// {
// 	int	width;
// 	int	height;

// 	height = 0;
// 	while (height < game.height)
// 	{

// 	}
// }

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 640, "hello world");
	get_img(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);

	return (0);
}