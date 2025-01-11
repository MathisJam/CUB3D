/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/11 13:21:32 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static void	check_mlx_win_init(t_data *data)
// {
// 	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080,
// 			"Nom de jeu provisoire");
// 	if (data->mlx_win == NULL)
// 		err_msg("Window initialization failed\n", data, true);
// }

// static void	check_mlx_ptr_init(t_data *data)
// {
// 	data->mlx_ptr = mlx_init();
// 	if (data->mlx_ptr == NULL)
// 		err_msg("Mlx initialization failed\n, data, true");
// }

void	set_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player_x = j;
				data->player_y = i;
			}
		}
	}
}

void	initialize(t_data *data)
{
	int	i;

	i = -1;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->row_nbr = 0;
	data->column_nbr = 0;
	data->map_start = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->textures = ft_calloc(1, sizeof(t_textures));
	data->textures->NO_path = NULL;
	data->textures->EA_path = NULL;
	data->textures->WE_path = NULL;
	data->textures->SO_path = NULL;
	data->textures->F = 0;
	data->textures->C = 0;
	data->textures->F_strings = 0;
	data->textures->C_strings = 0;
	// check_mlx_ptr_init(data);
	// check_mlx_win_init(data);
	// initialiser la map avec textures
}
