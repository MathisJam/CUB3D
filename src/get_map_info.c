/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:38:11 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 17:31:31 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*catch_path(char *line)
{
	char	*temp;

	temp = line;
	if (ft_strlen(temp) < 22)
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
	if (ft_strstr(line, "NO") && !data->NO->path)
		return (NO);
	else if (ft_strstr(line, "EA") && !data->EA->path)
		return (EA);
	else if (ft_strstr(line, "WE") && !data->WE->path)
		return (WE);
	else if (ft_strstr(line, "SO") && !data->SO->path)
		return (SO);
	else if (ft_strstr(line, "F") && !data->F_strings)
		return (F);
	else if (ft_strstr(line, "C") && !data->C_strings)
		return (C);
	return (-1);
}

static void	get_textures_info(t_data *data, char *line, int code)
{
	int	j;

	j = -1;
	if (code == NO && catch_path(line) != NULL)
		data->NO->path = strdup_without_n(catch_path(line));
	else if (code == EA && catch_path(line) != NULL)
		data->EA->path = strdup_without_n(catch_path(line));
	else if (code == WE && catch_path(line) != NULL)
		data->WE->path = strdup_without_n(catch_path(line));
	else if (code == SO && catch_path(line) != NULL)
		data->SO->path = strdup_without_n(catch_path(line));
	else if (code == F)
		data->F_strings = ft_split(line, ',');
	else if (code == C)
		data->C_strings = ft_split(line, ',');
}

static bool	valid_textures_info(t_data *data)
{
	if (!data->NO->path || !data->EA->path || !data->WE->path || !data->SO->path
		|| !data->F_strings || !data->C_strings)
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
		if (code > -1)
			get_textures_info(data, line, code);
		free(line);
		line = get_next_line(fd);
	}
	if (valid_textures_info(data) == false)
	{
		free(line);
		close(fd);
		err_msg("Missing textures paths\n", data, true);
	}
	free(line);
	close(fd);
}
