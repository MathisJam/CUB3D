/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/06 18:12:25 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
	{
		ft_putstr_fd("Error\n 1 argument required try : ./cub3d [map.cub]\n",
			2);
		exit(1);
	}
	initialize(&data, argv[1]);
	// CHECK SI MAP NULL POUR FREE_ALL?
	// mlx_hook(data.window->screen, 2, 0, handle_input, &data);
	// FAIRE FONCTION HANDLE INPUT POUR LES KEYS
	mlx_hook(data.window->screen, 17, 1, free_all, &data);
	mlx_loop(data.window->ptr);
}
