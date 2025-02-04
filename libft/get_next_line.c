/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:58:21 by jchen             #+#    #+#             */
/*   Updated: 2025/02/04 16:33:20 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*ft_get_line(char *buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	tmp = (char *)malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (buffer[i - 1] == '\n')
		tmp[i - 1] = '\n';
	tmp[i] = 0;
	while (--i >= 0)
		tmp[i] = buffer[i];
	return (tmp);
}

char	*ft_get_next(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer || !buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!tmp)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[++i])
		tmp[j++] = buffer[i];
	tmp[j] = 0;
	free(buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	int		bytes_read;

	if (!buffer)
	{
		buffer = (char *)malloc(1);
		buffer[0] = 0;
	}
	reading = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reading)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, reading, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(buffer, reading);
			return (NULL);
		}
		reading[bytes_read] = 0;
		buffer = ft_strjoin_free(buffer, reading);
	}
	free(reading);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_next(buffer);
	return (line);
}
