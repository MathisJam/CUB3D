/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:44:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/06 18:13:06 by mjameau          ###   ########.fr       */
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

int	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (data == NULL)
		return (1);
	// if (data->sprite[0])
	// 	while (++i <= 3)
	// 		mlx_destroy_image(data->window->ptr, data->sprite[i]);
	if (data->window->screen)
		mlx_destroy_window(data->window->ptr, data->window->screen);
	if (data->window->ptr)
	{
		mlx_destroy_display(data->window->ptr);
		free(data->window->ptr);
	}
	if (data->map)
		free_tab(data->map);
	exit(0);
}
