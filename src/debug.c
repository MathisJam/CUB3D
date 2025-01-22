/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:12:15 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 12:54:29 by jchen            ###   ########.fr       */
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

void	debug(t_data *data)
{
	int	count;

	printf("\nTABLEAU :\n");
	display_char_array(data->map);
	printf("\n");
	printf("row_nbr : %d\n", data->row_nbr);
	count = count_strings(data->f_strings);
	if (data->floor)
	{
		printf("Tableau d'entiers F : ");
		for (int i = 0; i < count; i++)
		{
			printf("%d ", data->floor[i]);
		}
		printf("\n");
	}
	count = count_strings(data->c_strings);
	if (data->ceiling)
	{
		printf("Tableau d'entiers C : ");
		for (int i = 0; i < count; i++)
		{
			printf("%d ", data->ceiling[i]);
		}
		printf("\n");
	}
	printf("Player x = %f\nPlayer y = %f\n", data->player->px,
		data->player->py);
	printf("no = %s\n", data->no->path);
	printf("so = %s\n", data->so->path);
	printf("we = %s\n", data->we->path);
	printf("ea = %s\n", data->ea->path);
}
