/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/08 16:49:37 by jchen            ###   ########.fr       */
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
	// INIT LES FLOATS?
	// check_mlx_ptr_init(data);
	// check_mlx_win_init(data);
	// set_position du player
	// initialiser la map avec textures
}
