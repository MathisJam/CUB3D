/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:36:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 17:28:22 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (is_space(line[i]) || line[i] == '1'))
		i++;
	if (line[i] == '\0')
		return (0);
	else
		return (1);
}

static int	double_char(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				flag++;
		}
	}
	if (flag != 1)
		return (1);
	else
		return (0);
}

static int	invalid_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& !is_space(map[i][j]))
				return (1);
		}
	}
	return (0);
}

static int	close_check(t_data *data, char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	if (check_line(map[0]))
		return (1);
	if (check_line(map[(data->row_nbr) - 1]))
		return (1);
	while (++i < (data->row_nbr))
	{
		j = 0;
		while (is_space(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (1);
		len = ft_strlen(map[i]) - 1;
		while (len > 0 && is_space(map[i][len]))
			len--;
		if (map[i][len] != '1')
			return (1);
	}
	if (i < 3)
		err_msg("Map not closed", data, true);
	return (0);
}

void	check_map(t_data *data)
{
	if (data->map_start < 7)
		err_msg("Don't forget the paths to the textures\n", data, true);
	if (close_check(data, data->map))
		err_msg("Map is not closed, or is not at the end\n", data, true);
	if (invalid_char(data->map))
		err_msg("Invalid char in map, please only use NSWE01\n", data, true);
	if (double_char(data->map))
		err_msg("Need one and only one N S W E char\n", data, true);
}
