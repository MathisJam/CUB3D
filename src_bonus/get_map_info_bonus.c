/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:38:11 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/05 14:37:32 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*catch_path(char *line)
{
	char	*temp;

	temp = line;
	if (ft_strlen(temp) < 2)
		return (NULL);
	while (*temp && *(temp + 1) && (*temp != '.' || *(temp + 1) != '/'))
	{
		temp++;
		if (!*temp || !*(temp + 1))
			return (NULL);
	}
	return (temp);
}

static int	is_texture(t_data *data, char *line)
{
	if (ft_strstr(line, "NO"))
		return (is_double_texture(data, NORTH), NORTH);
	else if (ft_strstr(line, "EA"))
		return (is_double_texture(data, EAST), EAST);
	else if (ft_strstr(line, "WE"))
		return (is_double_texture(data, WEST), WEST);
	else if (ft_strstr(line, "SO"))
		return (is_double_texture(data, SOUTH), SOUTH);
	else if (ft_strstr(line, "F"))
		return (is_double_texture(data, FNUM), FNUM);
	else if (ft_strstr(line, "C"))
		return (is_double_texture(data, CNUM), CNUM);
	return (-1);
}

static void	get_textures_info(t_data *data, char *line, int code)
{
	int	j;

	j = -1;
	if (code == NORTH && catch_path(line) != NULL && !data->no->path)
		data->no->path = strdup_without_n(catch_path(line));
	else if (code == EAST && catch_path(line) != NULL && !data->ea->path)
		data->ea->path = strdup_without_n(catch_path(line));
	else if (code == WEST && catch_path(line) != NULL && !data->we->path)
		data->we->path = strdup_without_n(catch_path(line));
	else if (code == SOUTH && catch_path(line) != NULL && !data->so->path)
		data->so->path = strdup_without_n(catch_path(line));
	else if (code == FNUM && !data->f_strings)
		data->f_strings = ft_split(line, ',');
	else if (code == CNUM && !data->c_strings)
		data->c_strings = ft_split(line, ',');
	else if (code == -1 && catch_path(line) != NULL)
		data->dup = true;
}

static bool	valid_textures_info(t_data *data)
{
	if (!data->no->path || !data->ea->path || !data->we->path || !data->so->path
		|| !data->f_strings || !data->c_strings)
		return (false);
	return (true);
}

void	get_map_info(t_data *data, char *map)
{
	int		fd;
	char	*line;
	int		code;

	code = 0;
	fd = safe_open_fd(map, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		code = is_texture(data, line);
		get_textures_info(data, line, code);
		free(line);
		line = get_next_line(fd);
	}
	if (valid_textures_info(data) == false || data->dup == true)
	{
		free(line);
		close(fd);
		if (data->dup == true)
			err_msg("Too many texture (duplicate or wrong texture)\n", data,
				true);
		err_msg("Missing textures paths\n", data, true);
	}
	free(line);
	close(fd);
}
