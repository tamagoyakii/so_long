/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:48:58 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/21 01:39:41 by jihyukim         ###   ########.fr       */
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
	img->bird[0].img = mlx_xpm_file_to_image(mlx_ptr, IMG_BR, &px, &px);
	img->bird[1].img = mlx_xpm_file_to_image(mlx_ptr, IMG_BL, &px, &px);
	img->exit[0].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E0, &px, &px);
	img->exit[1].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E1, &px, &px);
	img->exit[2].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E2, &px, &px);
	img->exit[3].img = mlx_xpm_file_to_image(mlx_ptr, IMG_E3, &px, &px);
	img->food[0].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C0, &px, &px);
	img->food[1].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C1, &px, &px);
	img->food[2].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C2, &px, &px);
	img->food[3].img = mlx_xpm_file_to_image(mlx_ptr, IMG_C3, &px, &px);
}

void	bird_patrol(t_win *win, t_map *map, int row, int col)
{
	static int	idx;

	if (idx++ >= 20)
	{
		if (map->map[row][col + map->dir] == 'P')
			game_over(map, win, row, col);
		else if (map->map[row][col + map->dir] == '0')
		{
			map->map[row][col + map->dir] = 'B';
			map->map[row][col] = '0';
		}
		else
			bird_dir_change(map);
		printf("%d, %d \n", map->dir, map->b);
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
		mlx_put_image_to_window(mlx, win, info->img.bird[info->map.b].img,
			col * PX, row * PX);
		bird_patrol(&info->win, &info->map, row, col);
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
	texture_change(info);
	step = ft_itoa(info->map.step);
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 9, 21, 0xFFFFFF, step);
	free(step);
	return (0);
}
