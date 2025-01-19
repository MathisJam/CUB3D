/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:17:40 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/19 11:25:27 by mjameau          ###   ########.fr       */
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
