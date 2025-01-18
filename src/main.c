/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/18 14:07:20 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	display_map(t_data *data)
{
	int	x;
	int	y;

	if (!data->textures->EA || !data->textures->SO)
		err_msg("Erreur lors du chargement des textures\n", data, true);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == ' ')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->textures->EA, x * 64, y * 64);
			else if (data->map[y][x] == 'S' || data->map[y][x] == 'N'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->textures->NO, x * 64, y * 64);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->textures->SO, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

static void	init_map(t_data *data, char **argv)
{
	load_map(data, argv[1]);
	check_map(data);
	get_map_info(data, argv[1]);
	get_floor_ceiling(data);
	set_player_pos(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_putstr_fd("Error\nMalloc failed\n", 2);
	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
		err_msg("please enter : ./cub3D [map.cub]\n", data, true);
	init_data(data);
	init_map(data, argv);
	// debug(data);
	init_mlx(data);
	init_textures(data);
	display_map(data);
	mlx_hook(data->mlx_win, 2, 0, handle_input, data);
	mlx_hook(data->mlx_win, 17, 1, free_all, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop(data->mlx_ptr);
	free_all(data, 0);
}
