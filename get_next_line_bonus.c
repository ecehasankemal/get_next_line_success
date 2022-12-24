/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:58:05 by hece              #+#    #+#             */
/*   Updated: 2022/12/24 21:05:38 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	typeof(t_mystruct) index;
	typeof(char *) str;
	index.i = 0;
	index.j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	while (s1[index.i])
		index.i++;
	while (s2[index.j])
		index.j++;
	str = (char *)malloc(sizeof(char) * (index.i + index.j + 1));
	index.i = 0;
	index.j = 0;
	if (!str)
		return (NULL);
	while (s1[index.i])
		str[index.i++] = s1[index.i];
	while (s2[index.j] != '\0')
		str[(index.i - 1) + index.j] = s2[index.j++];
	str[index.i + index.j] = '\0';
	free(s1);
	return (str);
}

char	*ft_new_create_buffer(char *buffer)
{
	typeof(int) index;
	typeof(int) jndex;
	typeof(char *) res;
	typeof(int) len;
	index = 0;
	len = 0;
	while (buffer[len])
		len++;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
	{
		free(buffer);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (len - index + 1));
	if (!res)
		return (NULL);
	index++;
	jndex = 0;
	while (buffer[index])
		res[jndex++] = buffer[index++];
	res[jndex] = '\0';
	free(buffer);
	return (res);
}

char	*ft_create_buffer(char *buffer, int buff_size, int fd)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while ((buff_size != 0 && !ft_strchr(buffer)))
	{
		buff_size = read(fd, temp, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[buff_size] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	if (buffer[0] == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static typeof(char *) buffer[1024];
	typeof(char *) line;
	typeof(int) index;
	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_create_buffer(buffer[fd], 1, fd);
	if (!buffer[fd])
		return (NULL);
	while (buffer[fd][index] && buffer[fd][index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = -1;
	while (buffer[fd][++index] && buffer[fd][index] != '\n')
		line[index] = buffer[fd][index];
	if (buffer[fd][index] == '\n')
	{
		line[index] = buffer[fd][index];
		index++;
	}
	line[index] = '\0';
	buffer[fd] = ft_new_create_buffer(buffer[fd]);
	return (line);
}
