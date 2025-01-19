/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/19 15:37:18 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_player(t_data *data)
{
	data->player = safe_calloc(1, sizeof(t_player), data);
	data->player->cam_height = 1.0;
	data->player->speed = 0.05;
	data->player->sens = 0.1;
}

void	init_controls(t_data *data)
{
	data->control = malloc(sizeof(t_control));
	if (!data->control)
		err_msg("malloc() failure in data->control\n", data, 1);
	data->control->look_left = 0;
	data->control->look_right = 0;
	data->control->look_up = 0;
	data->control->look_down = 0;
	data->control->move_left = 0;
	data->control->move_right = 0;
	data->control->move_fwd = 0;
	data->control->move_bwd = 0;
}

void	init_data(t_data *data)
{
	data->mlx_img = safe_calloc(1, sizeof(t_texture), data);
	data->NO = safe_calloc(1, sizeof(t_texture), data);
	data->SO = safe_calloc(1, sizeof(t_texture), data);
	data->WE = safe_calloc(1, sizeof(t_texture), data);
	data->EA = safe_calloc(1, sizeof(t_texture), data);
	init_player(data);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		err_msg("Mlx initialization failed\n", data, true);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3D");
	if (data->mlx_win == NULL)
		err_msg("Window initialization failed\n", data, true);
	data->mlx_img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT);
	if (!data->mlx_img->img_ptr)
		err_msg("mlx_new_image failed\n", data, true);
	data->mlx_img->width = WIN_WIDTH;
	data->mlx_img->height = WIN_HEIGHT;
	data->mlx_img->data = mlx_get_data_addr(data->mlx_img->img_ptr,
			&data->mlx_img->bits_per_pixel, &data->mlx_img->line_length,
			&data->mlx_img->endian);
}
