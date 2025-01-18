/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:52:01 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 14:07:58 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	render(void *arg)
{
	t_data	*data;
	t_ray	*ray;

	data = (t_data *)arg;
	ray = malloc(sizeof(t_ray));
	ft_bzero(ray, sizeof(t_ray));
	while (ray->curr_x < 1920)
		raytracing(data, ray);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img->img_ptr, 0, 0);
	free(ray);
	// INITIALISER STRUCTURE IMG
	// si on veut mettre event handler
}
