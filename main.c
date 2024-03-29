/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/11/19 17:40:55 by jihyukim         ###   ########.fr       */
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
	if (!info->win.mlx_ptr)
		error_exit(0);
	info->win.win_ptr = mlx_new_window(info->win.mlx_ptr,
			info->map.col * PX, info->map.row * PX, "so_long");
	if (!info->win.win_ptr)
		error_exit(0);
	set_img(info->win.mlx_ptr, &info->img);
	print_map(info);
	mlx_hook(info->win.win_ptr, ON_KEYDOWN, 0, key_press, info);
	mlx_hook(info->win.win_ptr, ON_DESTROY, 0, close_win, &info->win);
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
