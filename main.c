/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/06/11 17:00:54 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"

void get_img(void *mlx_ptr, void *win_ptr)
{
	void *mushroom;
	void *balloon;
	void *wall;
	void *land;
	int img_width;
	int img_height;

	mushroom = mlx_xpm_file_to_image(mlx_ptr, "./images/mushroom.xpm", &img_width, &img_height);
	balloon = mlx_xpm_file_to_image(mlx_ptr, "./images/balloon.xpm", &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	land = mlx_xpm_file_to_image(mlx_ptr, "./images/land.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, mushroom, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, balloon, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 128, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, land, 192, 64);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "hello world");
	get_img(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);

	return (0);
}