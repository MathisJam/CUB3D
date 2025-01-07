/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:04 by jchen             #+#    #+#             */
/*   Updated: 2025/01/07 14:20:14 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_map(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = safe_open_fd(map, O_RDONLY, data);
	line = get_next_line(fd);
	if (line != 0)
		data->column = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		data->line++;
	}
	free(line);
	close(fd);
	// data->x = data->column_nbr * 64;
	// data->y = data->row_nbr * 64;
	data->map = malloc_map(map, data);
}

char	**malloc_map(char *map, t_game_data *m_data)
{
	char **map_array;
	int fd;
	int i;

	fd = open(map, O_RDONLY);
	map_array = NULL;
	if (m_data->row_nbr != 0)
		map_array = malloc((m_data->row_nbr + 1) * sizeof(char *));
	if (!map_array)
		error_handler(MALLOC_FAILED, m_data);
	i = -1;
	while (m_data->row_nbr > ++i)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
		{
			free_map(map_array);
			error_handler(MALLOC_FAILED, m_data);
		}
	}
	map_array[i] = NULL;
	close(fd);
	return (map_array);
}
