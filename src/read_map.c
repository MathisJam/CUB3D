/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:04 by jchen             #+#    #+#             */
/*   Updated: 2025/01/08 11:51:07 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	data->x = data->column_nbr * 64;
	data->y = data->row_nbr * 64;
	data->map = malloc_map(map, data);
}

char	**malloc_map(char *map, t_data *data)
{
	char	**map_array;
	int		fd;
	int		i;
	int		start;

	fd = open(map, O_RDONLY);
	start = starting_row(map, data);
	map_array = NULL;
	if (data->row_nbr != 0)
		map_array = malloc((data->row_nbr + 1) * sizeof(char *));
	if (!map_array)
		return (NULL);
	i = 0;
	while (++i < start)
		get_next_line(fd);
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
