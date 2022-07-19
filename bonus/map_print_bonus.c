/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:48:58 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/19 16:29:29 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_img(void *mlx_ptr, t_img *img)
{
	int	px;

	px = PX;
	img->plyr = mlx_xpm_file_to_image(mlx_ptr, IMG_P, &px, &px);
	img->wall = mlx_xpm_file_to_image(mlx_ptr, IMG_1, &px, &px);
	img->emty = mlx_xpm_file_to_image(mlx_ptr, IMG_0, &px, &px);
	img->bird = mlx_xpm_file_to_image(mlx_ptr, IMG_B, &px, &px);
	img->exit[0].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E0, &px, &px);
	img->exit[1].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E1, &px, &px);
	img->exit[2].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E2, &px, &px);
	img->exit[3].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E3, &px, &px);
	img->food[0].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C0, &px, &px);
	img->food[1].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C1, &px, &px);
	img->food[2].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C2, &px, &px);
	img->food[3].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C3, &px, &px);
}

void	texture_change(t_info *info)
{
	static int	idx;

	if (idx++ >= 12)
	{
		if (info->map.t < 3)
			info->map.t++;
		else
			info->map.t = 0;
		idx = 0;
	}
}

void	bird_patrol(t_info *info, int row, int col)
{
	static int	idx;

	if (idx++ >= 30)
	{
		if (info->map.map[row][col + info->map.v] == '1'
			|| info->map.map[row][col + info->map.v] == 'E'
			|| info->map.map[row][col + info->map.v] == 'C')
		{
			if (info->map.v == 1)
				info->map.v = -1;
			else
				info->map.v = 1;
		}
		else
		{
			if (info->map.map[row][col + info->map.v] == 'P')
				game_over(&info->map, &info->win, row, col);
			info->map.map[row][col + info->map.v] = 'B';
			info->map.map[row][col] = '0';
		}
		idx = 0;
	}
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
	else if (info->map.map[row][col] == 'P')
		mlx_put_image_to_window(mlx, win, info->img.plyr, col * PX, row * PX);
	else if (info->map.map[row][col] == 'B')
	{
		mlx_put_image_to_window(mlx, win, info->img.bird, col * PX, row * PX);
		bird_patrol(info, row, col);
	}
	else if (info->map.map[row][col] == 'C')
		mlx_put_image_to_window(mlx, win, info->img.food[info->map.t].img,
			col * PX, row * PX);
	else if (info->map.map[row][col] == 'E')
		mlx_put_image_to_window(mlx, win, info->img.exit[info->map.t].img,
			col * PX, row * PX);
}

int	print_map(t_info *info)
{
	int		row;
	int		col;
	char	*step;

	row = -1;
	while (++row < info->map.row)
	{
		col = -1;
		while (++col < info->map.col)
		{
			put_img(info, row, col);
		}
	}
	step = ft_itoa(info->map.step);
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 9, 21, 0xFFFFFF, step);
	free(step);
	texture_change(info);
	return (0);
}
