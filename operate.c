/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:35:11 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/17 16:16:07 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alert(t_win *win, t_map *map_info)
{
	if (map_info->food == 0)
	{
		printf("Mission Complete!\n");
		close_win(win);
	}
	else
		printf("There are still a few crickets left.\n");
}

void	move(t_win *win, t_map *map_info, int row, int col)
{
	char	from;
	char	to;

	from = map_info->map[map_info->p_row][map_info->p_col];
	to =  map_info->map[map_info->p_row + row][map_info->p_col + col];
	if (to != '1')
	{
		if (to == 'E')
			alert(win, map_info);
		if (to == 'C')
			map_info->food -= 1;
		if (!(to == 'E') && map_info->food != 0)
		{
			map_info->map[map_info->p_row][map_info->p_col] = '0';
			map_info->p_row += row;
			map_info->p_col += col;
			map_info->map[map_info->p_row][map_info->p_col] = 'P';
			map_info->step += 1;
			printf("Steps : %d\n", map_info->step);
		}
	}
}

int	key_release(int keycode, t_info *info)
{
	if (keycode == 13)
		move(&info->win, &info->map, -1, 0);
	else if (keycode == 1)
		move(&info->win, &info->map, 1, 0);
	else if (keycode == 0)
		move(&info->win, &info->map, 0, -1);
	else if (keycode == 2)
		move(&info->win, &info->map, 0, 1);
	else if (keycode == 53)
		close_win(&info->win);
	return (0);
}

int	close_win(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
}