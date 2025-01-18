/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:02:00 by jchen             #+#    #+#             */
/*   Updated: 2025/01/18 17:40:17 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	*open_xpm(t_data *data, char *path)
{
	void	*sprite;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid texture path or right\n", data, true);
	close(fd);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->mlx_img->width,
			&data->mlx_img->height);
	if (!sprite)
		err_msg("Failed to open xpm\n", data, true);
	return (sprite);
}

void	init_textures(t_data *data)
{
	data->NO->img_ptr = open_xpm(data, data->NO->path);
	data->EA->img_ptr = open_xpm(data, data->EA->path);
	data->SO->img_ptr = open_xpm(data, data->SO->path);
	data->WE->img_ptr = open_xpm(data, data->WE->path);
}
