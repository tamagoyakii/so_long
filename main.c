/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/17 13:25:37 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"

void	set_img(void *mlx_ptr, t_img *img)
{
	int px;

	px = PX;
	img->plyr = mlx_xpm_file_to_image(mlx_ptr, IMG_P, &px, &px);
	img->coll = mlx_xpm_file_to_image(mlx_ptr, IMG_C, &px, &px);
	img->wall = mlx_xpm_file_to_image(mlx_ptr, IMG_1, &px, &px);
	img->emty = mlx_xpm_file_to_image(mlx_ptr, IMG_0, &px, &px);
	img->exit = mlx_xpm_file_to_image(mlx_ptr, IMG_E, &px, &px);
}

void	put_img(char c, t_win *win, t_img *img, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->emty, x, y);
	else if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->coll, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->emty, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->plyr, x, y);
}

void	print_map(t_map *map_info, t_win *win, t_img *img)
{
	int	row;
	int	column;

	set_img(win->mlx_ptr, img);
	row = -1;
	while(++row < map_info->row)
	{
		column = -1;
		while(++column < map_info->column)
		{
			put_img(map_info->map[row][column], win, img, column * PX, row * PX);
		}
	}
}

void	show_window(t_info *info)
{
	info->win.mlx_ptr = mlx_init();
	info->win.win_ptr = mlx_new_window(info->win.mlx_ptr,
		info->map.column * PX, info->map.row * PX, "so_long");
	print_map(&info->map, &info->win, &info->img);
	mlx_loop(info->win.mlx_ptr);
}

int main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		map_parse(&info, argv[1]);
		show_window(&info);
	}
	else
		error_exit("Wrong Parameters");
	return (0);
}