/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/15 11:28:43 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int	handle_input(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 		free_all(data, 0);
// 	else if (keysym == XK_a || keysym == XK_A)
// 		move(data, 'L');
// 	else if (keysym == XK_w || keysym == XK_W)
// 		move(data, 'U');
// 	else if (keysym == XK_s || keysym == XK_S)
// 		move(data, 'D');
// 	else if (keysym == XK_d || keysym == XK_D)
// 		move(data, 'R');
// 	else if (keysym == XK_Right)
// 		rotate_cam(data);
// 	else if (keysym == XK_Left)
// 		rotate_cam(data);
// 	return (0);
// }

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
	check_mlx_ptr_init(data);
	check_mlx_win_init(data);
	// mlx_hook(data->mlx_win, 2, 0, handle_input, data); // Finir ca
	mlx_hook(data->mlx_win, 17, 1, free_all, data);
	mlx_loop(data->mlx_ptr);
	free_all(data, 0);
}
