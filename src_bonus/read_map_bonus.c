/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:04 by jchen             #+#    #+#             */
/*   Updated: 2025/02/05 13:00:33 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	is_map_start(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) <= 1)
		return (false);
	while (str && (str[i] == '1' || str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\n' && i > 1)
		return (true);
	return (false);
}

int	load_map(t_data *data, char *map)
{
	int		fd;
	char	*line;
	int		i;
	bool	start;

	i = 0;
	start = false;
	fd = safe_open_fd(map, O_RDONLY, data);
	data->map = calloc_fd(1000, sizeof(char *), data, &fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map_start(line) == true)
			start = true;
		if (start)
		{
			free(data->map[i]);
			data->map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	return (free(line), close(fd));
}
