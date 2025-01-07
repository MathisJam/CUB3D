/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/06 18:44:53 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		err_msg("Malloc failed\n");
	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
	{
		err_msg("1 argument required, try : ");
		ft_putstr_fd(RED "./cub3D [map.cub]\n" RST, 2);
		exit(1);
	}
	initialize(data, argv[1]);
	// CHECK SI MAP NULL POUR FREE_ALL?
	// mlx_hook(data.window->mlx_win, 2, 0, handle_input, data);
	// FAIRE FONCTION HANDLE INPUT POUR LES KEYS
	mlx_hook(data->mlx_win, 17, 1, free_all, data);
	mlx_loop(data->mlx_ptr);
}
