/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/08 12:50:21 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_mlx_win_init(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080,
			"Nom de jeu provisoire");
	if (data->mlx_win == NULL)
	{
		err_msg("Window initialization failed\n");
		free_all(data, 1);
	}
}

static void	check_mlx_ptr_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		err_msg("Mlx initialization failed\n");
		free_all(data, 1);
	}
}

void	initialize(t_data *data, char *argv)
{
	int	i;

	(void)argv;
	i = -1;
	data->map = NULL;
	data->row_nbr = 0;
	data->column_nbr = 0;
	data->player_x = 0;
	data->player_y = 0;
	while (++i <= 3)
		data->sprite[i] = NULL;
	// load_map(data, argv[1]);
	check_mlx_ptr_init(data);
	check_mlx_win_init(data);
	// set_position du player
	// initialiser la map avec textures
}
