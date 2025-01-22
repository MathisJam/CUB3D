/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:17:40 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 12:34:43 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_camera(t_data *data, double d_y, double p_x, double p_y)
{
	if (data->player_found)
		err_msg("multiple player init\n", data, true);
	data->player->dir_vect.y = d_y;
	data->player->cam_plane_vect.x = p_x;
	data->player->cam_plane_vect.y = p_y;
	data->player_found++;
}

void	turn_left(t_data *data)
{
	double	og_dirx;
	double	og_planex;
	double	sens;

	og_dirx = data->player->dir_vect.x;
	og_planex = data->player->cam_plane_vect.x;
	sens = data->player->sens;
	data->player->dir_vect.x = data->player->dir_vect.x * cos(-sens)
		- data->player->dir_vect.y * sin(-sens);
	data->player->dir_vect.y = og_dirx * sin(-sens) + data->player->dir_vect.y
		* cos(-sens);
	data->player->cam_plane_vect.x = data->player->cam_plane_vect.x * cos(-sens)
		- data->player->cam_plane_vect.y * sin(-sens);
	data->player->cam_plane_vect.y = og_planex * sin(-sens)
		+ data->player->cam_plane_vect.y * cos(-sens);
}

void	turn_right(t_data *data)
{
	double	og_dirx;
	double	og_planex;
	double	sens;

	og_dirx = data->player->dir_vect.x;
	og_planex = data->player->cam_plane_vect.x;
	sens = data->player->sens;
	data->player->dir_vect.x = data->player->dir_vect.x * cos(sens)
		- data->player->dir_vect.y * sin(sens);
	data->player->dir_vect.y = og_dirx * sin(sens) + data->player->dir_vect.y
		* cos(sens);
	data->player->cam_plane_vect.x = data->player->cam_plane_vect.x * cos(sens)
		- data->player->cam_plane_vect.y * sin(sens);
	data->player->cam_plane_vect.y = og_planex * sin(sens)
		+ data->player->cam_plane_vect.y * cos(sens);
}
