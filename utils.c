/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:42:50 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/15 17:54:52 by jihyukim         ###   ########.fr       */
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

char	*ft_strdup_without_newline(const char *s1)
{
	char	*dst;
	int		len;
	int		i;

	len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (len));
	if (!(dst))
		return (0);
	i = 0;
	while (*(s1 + i + 1))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	*(dst + i) = 0;
	return (dst);
}