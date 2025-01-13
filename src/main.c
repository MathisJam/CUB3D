/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/13 12:46:22 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	display_char_array(char **array)
{
	int	i;

	if (!array)
	{
		printf("Le tableau est NULL.\n");
		return ;
	}
	i = 0;
	while (array[i])
	{
		printf("Element %d: %s", i, array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	int count; // DEBUG a enlever
	(void)argc;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_putstr_fd("Error\nMalloc failed\n", 2);
	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
		err_msg("please enter : ./cub3D [map.cub]\n", data, true);
	initialize(data);
	// // CHECK SI MAP NULL POUR FREE_ALL?
	// // mlx_hook(data.window->mlx_win, 2, 0, handle_input, data);
	// // FAIRE FONCTION HANDLE INPUT POUR LES KEYS
	// mlx_hook(data->mlx_win, 17, 1, free_all, data);
	// mlx_loop(data->mlx_ptr);
	load_map(data, argv[1]);
	check_map(data);
	get_map_info(data, argv[1]);
	get_floor_ceiling(data);
	set_player_pos(data);
	//----------------------------------------------------PARTIE DEBUG--------------------------------------------------
	display_char_array(data->map);
	printf("row_nbr : %d\n", data->row_nbr);
	count = count_strings(data->textures->F_strings);
	if (data->textures->F)
	{
		printf("Tableau d'entiers F : ");
		for (int i = 0; i < count; i++)
		{
			printf("%d ", data->textures->F[i]);
		}
		printf("\n");
	}
	count = count_strings(data->textures->C_strings);
	if (data->textures->C)
	{
		printf("Tableau d'entiers C : ");
		for (int i = 0; i < count; i++)
		{
			printf("%d ", data->textures->C[i]);
		}
		printf("\n");
	}
	printf("Player x = %d\n Player y = %d\n", data->player_x, data->player_y);
	//----------------------------------------------------FIN PARTIE DEBUG--------------------------------------------------
	free_all(data, 0);
}
