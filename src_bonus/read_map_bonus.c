/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:04 by jchen             #+#    #+#             */
/*   Updated: 2025/01/24 12:18:22 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	is_map_start(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 1)
		return (false);
	while (str && (str[i] == '1' || str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\n' && i > 1)
		return (true);
	return (false);
}

static int	is_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '\t' || c == ' ');
}

static int	map_line_nbr(char *str, t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	int		start;
	int		j;

	i = 0;
	start = 0;
	fd = safe_open_fd(str, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		j = 0;
		// while (line && (line[j] == '1' || line[j] == ' '))
		while (line && is_char(line[j]))
			j++;
		if (j > 1 && (line[j] == '\n'))
		{
			start = i;
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), start);
}

static void	skip_not_map_lines(int fd, int start)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (++i < start)
	{
		temp = get_next_line(fd);
		j = 0;
		while (temp[j] == '1' || temp[j] == '0' || temp[j] == 'N'
			|| temp[j] == 32 || temp[j] == 'S' || temp[j] == 'W'
			|| temp[j] == 'E')
		{
			if (temp[j + 1] && (temp[j + 1] == '\n' || temp[j + 1] == '\0'))
				i--;
			j++;
		}
		free(temp);
	}
}

void	load_map(t_data *data, char *map)
{
	int		fd;
	char	*line;
	int		start;
	int		i;

	i = 0;
	start = 0;
	fd = safe_open_fd(map, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		if (is_map_start(line) == true)
		{
			start = i;
			data->column_nbr = ft_strlen(line) - 1;
		}
		if (start)
			data->row_nbr++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map = malloc_map(map, data);
}

char	**malloc_map(char *map, t_data *data)
{
	char	**map_array;
	int		fd;
	int		i;

	data->map_start = map_line_nbr(map, data);
	if (!(data->map_start) || data->row_nbr == 0)
		err_msg("Map not found\n", data, true);
	fd = open(map, O_RDONLY);
	map_array = malloc_fd((data->row_nbr + 1) * sizeof(char *), data, &fd);
	skip_not_map_lines(fd, data->map_start);
	i = -1;
	while (data->row_nbr > ++i)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
		{
			close(fd);
			err_msg("Copy map process failed\n", data, true);
		}
	}
	map_array[i] = NULL;
	return (close(fd), map_array);
}
