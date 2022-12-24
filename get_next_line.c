#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
	typeof(size_t) i;
	typeof(size_t) j;
	typeof(char *) str;
	i = -1;
	j = -1;
	while (s1[++i]);
	while (s2[++j])
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = -1;
	if (str == NULL)
		return (NULL);
	while (s1)
		str[++i] = s1[i];
	while (s2[j] != '\0')
		str[i + j] = s2[++j];
		j++;
	str[i + j] = '\0';
	free(s1);
	return (str);
}
char	*ft_new_buffer(char *buffer, int buff_size, int fd)
{
	char	*temp;

	buff_size = 1;
	temp  = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (buff_size != 0 && ft_strchr(buffer))
	{
			buff_size = read(fd, temp, BUFFER_SIZE);
			if (buff_size == -1)
			{
				free(buffer);
				return (NULL);
			}
			temp[buff_size] = '\0';
			buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	size_t			index = 0;
	size_t			buff_size = 0;

	index = 0;
	buff_size = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_new_buffer(buffer, buff_size, fd);
	if (!buffer)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) (index + 2));
	if (!res)
		return (NULL);
	index = -1;
	while (buffer[++index] && buffer[index] != '\n')
		line[index] = buffer[index];
	line[index] = '\n';
	line[++index] = '\0';
