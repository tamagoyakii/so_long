/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:02:56 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/19 14:12:12 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	text_exit(void *mlx_ptr, t_img *img)
{
	int px;

	px = PX;
	img->exit[0] = mlx_xpm_file_to_image(mlx_ptr, "./images/exit", &px, &px);
	img->exit[1] = mlx_xpm_file_to_image(mlx_ptr, "./images/exit2", &px, &px);
	img->exit[2] = mlx_xpm_file_to_image(mlx_ptr, "./images/exit3", &px, &px);
	img->exit[3] = mlx_xpm_file_to_image(mlx_ptr, "./images/exit4", &px, &px);
}