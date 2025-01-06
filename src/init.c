/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/06 18:12:49 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_screen_init(t_data *data)
{
	data->window->screen = mlx_new_window(data->window->ptr, data->x, data->y,
			"Nom de jeu provisoire");
	if (data->window->screen == NULL)
	{
		ft_putstr_fd("Error\n Window initialization failed\n", 2);
		free_all(data);
	}
}

static void	check_ptr_init(t_data *data)
{
	data->window->ptr = mlx_init();
	if (data->window->ptr == NULL)
	{
		ft_putstr_fd("Error\n Mlx initialization failed\n", 2);
		free_all(data);
	}
}

void	initialize(t_data *data, char *argv)
{
	int	i;

	(void)argv;
	i = -1;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->player_x = 0;
	data->player_y = 0;
	check_ptr_init(data);
	// while (++i <= 3)
	// 	data->sprite[i] = NULL;
	// read la map ?
	check_screen_init(data);
	// set_position du player
	// initialiser la map avec textures
}
