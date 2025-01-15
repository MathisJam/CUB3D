/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:44:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/15 11:29:20 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_extension(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = len - 1;
	j = 3;
	if (i <= j)
		return (1);
	while (big[i] == little[j])
	{
		if (little[j] == big[i] && j == 0)
			return (0);
		j--;
		i--;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	err_msg(char *str, t_data *data, bool to_free)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (to_free == true)
		free_all(data, 1);
}

void	free_textures(t_data *data)
{
	if (data->textures->NO)
		mlx_destroy_image(data->mlx_ptr, data->textures->NO);
	if (data->textures->NO_path)
		free(data->textures->NO_path);
	if (data->textures->EA)
		mlx_destroy_image(data->mlx_ptr, data->textures->EA);
	if (data->textures->EA_path)
		free(data->textures->EA_path);
	if (data->textures->SO)
		mlx_destroy_image(data->mlx_ptr, data->textures->SO);
	if (data->textures->SO_path)
		free(data->textures->SO_path);
	if (data->textures->WE)
		mlx_destroy_image(data->mlx_ptr, data->textures->WE);
	if (data->textures->WE_path)
		free(data->textures->WE_path);
	if (data->textures->C)
		free(data->textures->C);
	if (data->textures->C_strings)
		free_tab(data->textures->C_strings);
	if (data->textures->F)
		free(data->textures->F);
	if (data->textures->F_strings)
		free_tab(data->textures->F_strings);
}

int	free_all(t_data *data, int exit_status)
{
	int	i;

	i = -1;
	if (data == NULL)
		return (1);
	if (data->textures)
	{
		free_textures(data);
		free(data->textures);
	}
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
