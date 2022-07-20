/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:35:11 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/21 01:43:44 by jihyukim         ###   ########.fr       */
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
		else if (to == '0')
			map_change(map_info, row, col, '0');
		else if (to == 'C')
		{
			if (map_info->b == 2)
			{
				map_info->b = 0;
				map_change(map_info, row, col, 'B');
			}
			else
				map_change(map_info, row, col, '0');
			map_info->food -= 1;
		}
		else if (to == 'B')
			game_over(map_info, win, row, col);
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
