/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/22 19:19:10 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static void	display_char_array(char **array)
// {
// 	int	i;

// 	if (!array)
// 	{
// 		printf("Le tableau est NULL.\n");
// 		return ;
// 	}
// 	i = 0;
// 	while (array[i])
// 	{
// 		printf("Element %d: %s", i, array[i]);
// 		i++;
// 	}
// }

// static void	debug(t_data *data)
// {
// 	int	count;

// 	printf("\nTABLEAU :\n");
// 	display_char_array(data->map);
// 	printf("\n");
// 	printf("row_nbr : %d\n", data->row_nbr);
// 	count = count_strings(data->f_strings);
// 	if (data->floor)
// 	{
// 		printf("Tableau d'entiers F : ");
// 		for (int i = 0; i < count; i++)
// 		{
// 			printf("%d ", data->floor[i]);
// 		}
// 		printf("\n");
// 	}
// 	count = count_strings(data->c_strings);
// 	if (data->ceiling)
// 	{
// 		printf("Tableau d'entiers C : ");
// 		for (int i = 0; i < count; i++)
// 		{
// 			printf("%d ", data->ceiling[i]);
// 		}
// 		printf("\n");
// 	}
// 	printf("Player x = %f\nPlayer y = %f\n", data->player->px,
// 		data->player->py);
// 	printf("no = %s\n", data->no->path);
// 	printf("so = %s\n", data->so->path);
// 	printf("we = %s\n", data->we->path);
// 	printf("ea = %s\n", data->ea->path);
// }

static void	global_init(t_data *data, char **argv)
{
	init_data(data);
	load_map(data, argv[1]);
	// debug(data);
	check_map(data);
	get_map_info(data, argv[1]);
	get_floor_ceiling(data);
	init_mlx(data);
	init_textures(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_putstr_fd("Error\nData calloc failed\n", 2);
	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
		err_msg("please enter : ./cub3D [map.cub]\n", data, true);
	global_init(data, argv);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_hook(data->mlx_win, 17, 0, free_all, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, handle_key_release, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop(data->mlx_ptr);
	free_all(data, 0);
}
