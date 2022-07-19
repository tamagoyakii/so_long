/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:48:58 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/19 23:46:08 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(void *mlx_ptr, t_img *img)
{
	int	px;

	px = PX;
	img->plyr = mlx_xpm_file_to_image(mlx_ptr, IMG_P, &px, &px);
	img->food = mlx_xpm_file_to_image(mlx_ptr, IMG_C, &px, &px);
	img->wall = mlx_xpm_file_to_image(mlx_ptr, IMG_1, &px, &px);
	img->emty = mlx_xpm_file_to_image(mlx_ptr, IMG_0, &px, &px);
	img->exit = mlx_xpm_file_to_image(mlx_ptr, IMG_E, &px, &px);
}

void	put_img(t_info *info, int row, int col)
{
	void	*mlx;
	void	*win;

	mlx = info->win.mlx_ptr;
	win = info->win.win_ptr;
	if (info->map.map[row][col] == '0')
		mlx_put_image_to_window(mlx, win, info->img.emty, col * PX, row * PX);
	else if (info->map.map[row][col] == '1')
		mlx_put_image_to_window(mlx, win, info->img.wall, col * PX, row * PX);
	else if (info->map.map[row][col] == 'C')
		mlx_put_image_to_window(mlx, win, info->img.food, col * PX, row * PX);
	else if (info->map.map[row][col] == 'E')
		mlx_put_image_to_window(mlx, win, info->img.exit, col * PX, row * PX);
	else if (info->map.map[row][col] == 'P')
		mlx_put_image_to_window(mlx, win, info->img.plyr, col * PX, row * PX);
}

int	print_map(t_info *info)
{
	int	row;
	int	col;

	row = -1;
	while (++row < info->map.row)
	{
		col = -1;
		while (++col < info->map.col)
		{
			put_img(info, row, col);
		}
	}
	return (0);
}
