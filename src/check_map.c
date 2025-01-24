/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:36:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 16:05:38 by mjameau          ###   ########.fr       */
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

void	not_empty(char **map, int y, int x, t_data *data)
{
	if (map[y + 1] && map[y - 1] && map[y + 1][x - 1] && map[y + 1][x + 1]
		&& map[y - 1][x - 1] && map[y - 1][x + 1] && (map[y - 1][x - 1] != '\0'
			&& map[y - 1][x] != '\0' && map[y - 1][x - 1] != '\0' && map[y][x
			- 1] != '\0' && map[y][x] != '\0' && map[y][x + 1] != '\0' && map[y
			+ 1][x - 1] != '\0' && map[y + 1][x] != '\0' && map[y + 1][x
			+ 1] != '\0'))
		return ;
	err_msg("Player outside the map\n", data, true);
}

static int	double_char(char **map, t_data *data)
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
			{
				not_empty(map, i, j, data);
				flag++;
			}
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
	int	l;

	i = -1;
	if (check_line(map[0]) || check_line(map[(data->row_nbr) - 1]))
		return (1);
	while (++i < (data->row_nbr))
	{
		j = 0;
		while (is_space(map[i][j]))
			j++;
		l = ft_strlen(map[i]) - 1;
		while (l > 0 && is_space(map[i][l]))
			l--;
		if (map[i][j] != '1' || map[i][l] != '1' || (map[i + 1] && map[i + 1][l
				+ 1] && (!is_wall(map[i + 1][l - 1]) && !is_wall(map[i + 1][l])
					&& !is_wall(map[i + 1][l + 1]))))
			return (1);
		while (map[i][j++])
			validate_player(data, data->map, i, j);
	}
	if (i < 3)
		err_msg("Map not closed", data, true);
	return (0);
}

void	check_map(t_data *data)
{
	if (!data->map)
		err_msg("Map not found in CHECK MAP\n", data, true);
	if (data->map_start < 7)
		err_msg("Don't forget the paths to the textures\n", data, true);
	if (invalid_char(data->map))
		err_msg("Invalid char in map, or not at the end\n", data, true);
	if (close_check(data, data->map))
		err_msg("Map is not closed, or is not at the end\n", data, true);
	if (double_char(data->map, data))
		err_msg("Need one and only one N S W E char\n", data, true);
}
