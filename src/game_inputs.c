/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:48:32 by jchen             #+#    #+#             */
/*   Updated: 2025/01/18 13:51:19 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	move(t_data *data, int new_x, int new_y)
{
	int	y;
	int	x;

	y = data->player_y;
	x = data->player_x;
	if (data->map[new_y][new_x] == '0')
	{
		data->map[y][x] = '0';
		data->player_y = new_y;
		data->player_x = new_x;
		data->map[new_y][new_x] = 'S';
	}
	display_map(data);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("\rA la prochaine!");
		free_all(data, 0);
	}
	else if (keysym == XK_w || keysym == XK_W)
		move(data, data->player_x, data->player_y - 1);
	else if (keysym == XK_a || keysym == XK_A)
		move(data, data->player_x - 1, data->player_y);
	else if (keysym == XK_s || keysym == XK_S)
		move(data, data->player_x, data->player_y + 1);
	else if (keysym == XK_d || keysym == XK_D)
		move(data, data->player_x + 1, data->player_y);
	// else if (keysym == XK_Right)
	// 	rotate_cam(data);
	// else if (keysym == XK_Left)
	// 	rotate_cam(data);
	return (0);
}
