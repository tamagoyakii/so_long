/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:35:11 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/19 13:45:39 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	alert(t_win *win, t_map *map_info)
{
	if (map_info->food == 0)
	{
		map_info->step += 1;
		close_win(win);
	}
	else
		printf("There are still a few crickets left.\n");
}

void	map_change(t_map *map_info, int row, int col, char c)
{
	if (c == 'D')
		map_info->map[map_info->p_row][map_info->p_col] = '0';
	else
	{
		map_info->map[map_info->p_row][map_info->p_col] = c;
		map_info->map[map_info->p_row + row][map_info->p_col + col] = 'P';
	}
	map_info->p_row += row;
	map_info->p_col += col;
	map_info->step += 1;
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
			map_change(map_info, row, col, '0');
		if (to == 'C')
		{
			map_change(map_info, row, col, 'B');
			map_info->food -= 1;
		}
		if (to == 'B')
		{
			map_change(map_info, row, col, 'D');
			printf("GAME OVER!\n");
			close_win(win);
		}
	}
}

int	key_press(int keycode, t_info *info)
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
	print_map(info);
	return (0);
}
