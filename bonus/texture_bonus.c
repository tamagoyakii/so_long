/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:18:02 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/21 01:33:44 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	bird_dir_change(t_map *map)
{
	if (map->dir == 1)
	{
		map->dir = -1;
		map->b = 1;
	}
	else
	{
		map->dir = 1;
		map->b = 0;
	}
}
