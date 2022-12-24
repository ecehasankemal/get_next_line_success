/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:29:35 by hece              #+#    #+#             */
/*   Updated: 2022/12/24 22:29:39 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_mystruct
{
	int	i;
	int	j;
}				t_mystruct;

char	*get_next_line(int fd);
char	*ft_new_create_buffer(char *buffer);
char	*ft_create_buffer(char *buffer, int buff_size, int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
