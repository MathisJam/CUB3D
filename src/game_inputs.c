/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:48:32 by jchen             #+#    #+#             */
/*   Updated: 2025/01/19 12:54:28 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("\rA la prochaine!");
		free_all(data, 0);
	}
	return (0);
}
