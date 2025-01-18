/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:02:00 by jchen             #+#    #+#             */
/*   Updated: 2025/01/18 13:30:49 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	*open_xpm(t_data *data, char *path)
{
	void	*sprite;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid texture path\n", data, true);
	close(fd);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->textures->img_size, &data->textures->img_size);
	if (!sprite)
		err_msg("Failed to open xpm\n", data, true);
	return (sprite);
}

void	init_textures(t_data *data)
{
	data->textures->NO = open_xpm(data, data->textures->NO_path);
	data->textures->EA = open_xpm(data, data->textures->EA_path);
	data->textures->SO = open_xpm(data, data->textures->SO_path);
	data->textures->WE = open_xpm(data, data->textures->WE_path);
}
