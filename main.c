/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/18 18:50:26 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	if (str)
		printf("Error\n%s", str);
	else
		perror("Error\n");
	exit(1);
}

void	show_win(t_info *info)
{
	info->win.mlx_ptr = mlx_init();
	info->win.win_ptr = mlx_new_window(info->win.mlx_ptr,
			info->map.col * PX, info->map.row * PX, "so_long");
	set_img(info->win.mlx_ptr, &info->img);
	print_map(info);
	mlx_hook(info->win.win_ptr, 2, 0, key_press, info);
	mlx_hook(info->win.win_ptr, 17, 0, close_win, &info->win);
	mlx_loop_hook(info->win.mlx_ptr, print_map, info);
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
