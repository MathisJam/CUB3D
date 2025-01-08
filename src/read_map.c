/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:04 by jchen             #+#    #+#             */
/*   Updated: 2025/01/08 15:01:47 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	is_starting_row(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 1)
		return (false);
	while (str && (str[i] == '1' || str[i] == ' '))
		i++;
	if (str[i] == '\n')
		return (true);
	return (false);
}

static int	starting_row_nbr(char *str, t_data *data)
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
		while (line && (line[j] == '1' || line[j] == ' '))
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
	char	*temp;

	i = 0;
	while (++i < start)
	{
		temp = get_next_line(fd);
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
	if (line != 0)
		data->column_nbr = ft_strlen(line) - 1;
	while (line != NULL)
	{
		i++;
		if (is_starting_row(line) == true)
			start = i;
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
	int		start;

	start = starting_row_nbr(map, data);
	printf("starting row nbr = %d\n", start);
	fd = open(map, O_RDONLY);
	map_array = NULL;
	if (data->row_nbr != 0)
		map_array = safe_malloc((data->row_nbr + 1) * sizeof(char *), data);
	skip_not_map_lines(fd, start);
	i = -1;
	while (data->row_nbr > ++i)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
			return (free_tab(map_array), NULL);
	}
	map_array[i] = NULL;
	close(fd);
	return (map_array);
}
