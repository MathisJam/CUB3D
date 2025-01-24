/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:48:32 by jchen             #+#    #+#             */
/*   Updated: 2025/01/22 12:39:38 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_forward(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->map[(int)(player->py)][(int)(player->px + player->dir_vect.x
			* ceil(player->speed))] != '1'
		&& data->map[(int)(player->py)][(int)(player->px + player->dir_vect.x
			* ceil(player->speed))] != 32)
		player->px += (player->speed * player->dir_vect.x);
	if (data->map[(int)(player->py + player->dir_vect.y
			* ceil(player->speed))][(int)(player->px)] != '1'
		&& data->map[(int)(player->py + player->dir_vect.y
			* ceil(player->speed))][(int)(player->px)] != 32)
		player->py += (player->speed * player->dir_vect.y);
}

void	move_right(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->map[(int)(player->py)][(int)(player->px + player->cam_plane_vect.x
			* ceil(player->speed))] != '1'
		&& data->map[(int)(player->py)][(int)(player->px
			+ player->cam_plane_vect.x * ceil(player->speed))] != 32)
		player->px += (player->speed * player->cam_plane_vect.x);
	if (data->map[(int)(player->py + player->cam_plane_vect.y
			* ceil(player->speed))][(int)(player->px)] != '1'
		&& data->map[(int)(player->py + player->cam_plane_vect.y
			* ceil(player->speed))][(int)(player->px)] != 32)
		player->py += (player->speed * player->cam_plane_vect.y);
}

void	move_left(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->map[(int)(player->py)][(int)(player->px - player->cam_plane_vect.x
			* ceil(player->speed))] != '1'
		&& data->map[(int)(player->py)][(int)(player->px
			- player->cam_plane_vect.x * ceil(player->speed))] != 32)
		player->px -= (player->speed * player->cam_plane_vect.x);
	if (data->map[(int)(player->py - player->cam_plane_vect.y
			* ceil(player->speed))][(int)(player->px)] != '1'
		&& data->map[(int)(player->py - player->cam_plane_vect.y
			* ceil(player->speed))][(int)(player->px)] != 32)
		player->py -= (player->speed * player->cam_plane_vect.y);
}

void	move_backward(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->map[(int)(player->py)][(int)(player->px - player->dir_vect.x
			* ceil(player->speed))] != '1'
		&& data->map[(int)(player->py)][(int)(player->px - player->dir_vect.x
			* ceil(player->speed))] != 32)
		player->px -= (player->speed * player->dir_vect.x);
	if (data->map[(int)((player->py - player->dir_vect.y
				* ceil(player->speed)))][(int)(player->px)] != '1'
		&& data->map[(int)((player->py - player->dir_vect.y
				* ceil(player->speed)))][(int)(player->px)] != 32)
		player->py -= (player->speed * player->dir_vect.y);
}
