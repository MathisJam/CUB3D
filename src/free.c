/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:44:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 17:37:52 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

// void	free_textures(t_data *data)
// {
// 	if (data->NO->img_ptr)
// 		mlx_destroy_image(data->mlx_ptr, data->NO->img_ptr);
// 	if (data->NO->path)
// 		free(data->NO->path);
// 	if (data->SO->img_ptr)
// 		mlx_destroy_image(data->mlx_ptr, data->SO->img_ptr);
// 	if (data->SO->path)
// 		free(data->SO->path);
// 	if (data->EA->img_ptr)
// 		mlx_destroy_image(data->mlx_ptr, data->EA->img_ptr);
// 	if (data->EA->path)
// 		free(data->EA->path);
// 	if (data->WE->img_ptr)
// 		mlx_destroy_image(data->mlx_ptr, data->WE->img_ptr);
// 	if (data->WE->path)
// 		free(data->WE->path);
// 	if (data->C)
// 		free(data->C);
// 	if (data->C_strings)
// 		free_tab(data->C_strings);
// 	if (data->F)
// 		free(data->F);
// 	if (data->F_strings)
// 		free_tab(data->F_strings);
// }

int	free_all(t_data *data, int exit_status)
{
	int	i;

	i = -1;
	if (data == NULL)
		return (1);
	// if (data->textures)
	// {
	// 	free_textures(data);
	// 	free(data->textures);
	// }
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		free_tab(data->map);
	if (data)
		free(data);
	exit(exit_status);
}

void	err_msg(char *str, t_data *data, bool to_free)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (to_free == true)
		free_all(data, 1);
}
