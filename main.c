/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/17 14:49:55 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_win(t_info *info)
{
	info->win.mlx_ptr = mlx_init();
	info->win.win_ptr = mlx_new_window(info->win.mlx_ptr,
		info->map.col * PX, info->map.row * PX, "so_long");
	print_map(&info->map, &info->win, &info->img);
	mlx_loop(info->win.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		map_parse(&info, argv[1]);
		show_win(&info);
	}
	else
		error_exit("Wrong Parameters");
	return (0);
}