/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:52:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/04 19:24:10 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	invalid_char(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '\n' && !map[i + 1])
			err_msg("Map not at the end\n", data, true);
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\t')
				err_msg("No tab allowed, please use space\n", data, true);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& !is_space(map[i][j]))
				return (1);
		}
	}
	return (0);
}

int	get_map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	is_double_texture(t_data *data, int code)
{
	if ((code == NORTH && data->no->path) || (code == EAST && data->ea->path)
		|| (code == SOUTH && data->so->path) || (code == WEST && data->we->path)
		|| (code == FNUM && data->f_strings) || (code == CNUM
			&& data->c_strings))
		data->dup = true;
	// err_msg("Too many texture\n", data, true);
}
