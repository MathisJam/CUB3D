/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:02:00 by jchen             #+#    #+#             */
/*   Updated: 2025/01/19 12:19:12 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	open_xpm(t_data *data, t_texture *coord)
{
	int	fd;

	fd = open(coord->path, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid texture path or right\n", data, true);
	close(fd);
	coord->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, coord->path,
			&data->mlx_img->width, &data->mlx_img->height);
	if (!coord->img_ptr)
		err_msg("Failed to open xpm\n", data, true);
	coord->width = data->mlx_img->width;
	coord->height = data->mlx_img->height;
	coord->data = mlx_get_data_addr(coord->img_ptr, &coord->bits_per_pixel,
			&coord->line_length, &coord->endian);
}

void	init_textures(t_data *data)
{
	open_xpm(data, data->NO);
	open_xpm(data, data->EA);
	open_xpm(data, data->SO);
	open_xpm(data, data->WE);
}
