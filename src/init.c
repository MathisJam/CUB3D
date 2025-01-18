/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 15:35:48 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_img(t_data *data)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		err_msg("malloc() failure in img\n", data, 1);
	data->mlx_img = malloc(sizeof(t_image));
	ft_bzero(data->mlx_img, sizeof(t_image));
}

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

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		err_msg("malloc() failure in data->player\n", data, 1);
	data->player->dir_vect.x = 0;
	data->player->dir_vect.y = 0;
	data->player->cam_plane_vect.x = 0;
	data->player->cam_plane_vect.y = 0;
	data->player->px = 5;
	data->player->py = 5;
	data->player->sens = 0.1;
	data->player->speed = 0.05;
	data->player->cam_height = 1.0;
}

void	init_data(t_data *data)
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
	data->textures->img_size = 64;
	data->textures->NO_path = NULL;
	data->textures->EA_path = NULL;
	data->textures->WE_path = NULL;
	data->textures->SO_path = NULL;
	data->textures->F = 0;
	data->textures->C = 0;
	data->textures->F_strings = 0;
	data->textures->C_strings = 0;
	init_player(data);
	init_img(data);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		err_msg("Mlx initialization failed\n", data, true);
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080,
			"Nom de jeu provisoire");
	if (data->mlx_win == NULL)
		err_msg("Window initialization failed\n", data, true);
}
