/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/19 15:39:09 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_map(t_data *data, char **argv)
{
	load_map(data, argv[1]);
	check_map(data);
	get_map_info(data, argv[1]);
	get_floor_ceiling(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_putstr_fd("Error\nData calloc failed\n", 2);
	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
		err_msg("please enter : ./cub3D [map.cub]\n", data, true);
	init_data(data);
	init_controls(data);
	init_map(data, argv);
	init_mlx(data);
	// debug(data);
	init_textures(data);
	mlx_hook(data->mlx_win, 17, 0, free_all, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, handle_key_release, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop(data->mlx_ptr);
	free_all(data, 0);
}
