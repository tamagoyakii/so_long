/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:29:08 by jihyukim          #+#    #+#             */
/*   Updated: 2022/06/12 18:59:46 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	int	x;
	int	y;
}				t_param;
typedef struct s_game{
	int	width;
	int height;
}				t_game;

char	*get_next_line(int fd);
char	*get_until_newline(char *line_merged, char *backup);
char	*get_line(char *line_merged, char *backup);
void	gnl_bzero(char *backup);
size_t	ft_strlen(const char *s);
int		gnl_strchr(const char *s);
void	gnl_strlcpy(char *dst, const char *src, int dstsize);
char	*gnl_strjoin(char *s1, char *s2);

#endif