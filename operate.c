/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:35:11 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/19 23:47:14 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alert(t_win *win, t_map *map_info)
{
	if (map_info->food == 0)
	{
		map_info->step += 1;
		printf("Steps: %d\nMission Complete!\n", map_info->step);
		close_win(win);
	}
	else
		printf("There are still a few crickets left.\n");
}

void	map_change(t_map *map_info, int row, int col)
{
	map_info->map[map_info->p_row][map_info->p_col] = '0';
	map_info->map[map_info->p_row + row][map_info->p_col + col] = 'P';
	map_info->p_row += row;
	map_info->p_col += col;
	map_info->step += 1;
	printf("Steps: %d\n", map_info->step);
}

void	move(t_win *win, t_map *map_info, int row, int col)
{
	char	to;

	to = map_info->map[map_info->p_row + row][map_info->p_col + col];
	if (to != '1')
	{
		if (to == 'E')
			alert(win, map_info);
		if (to == '0')
			map_change(map_info, row, col);
		if (to == 'C')
		{
			map_change(map_info, row, col);
			map_info->food -= 1;
		}
	}
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		move(&info->win, &info->map, -1, 0);
	else if (keycode == KEY_S)
		move(&info->win, &info->map, 1, 0);
	else if (keycode == KEY_A)
		move(&info->win, &info->map, 0, -1);
	else if (keycode == KEY_D)
		move(&info->win, &info->map, 0, 1);
	else if (keycode == KEY_ESC)
		close_win(&info->win);
	print_map(info);
	return (0);
}

int	close_win(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	printf("See you later!\n");
	exit(0);
}
