/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:12:15 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/15 12:23:15 by jchen            ###   ########.fr       */
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
	printf("Player x = %d\nPlayer y = %d\n", data->player_x, data->player_y);
	printf("NO = %s\n", data->textures->NO_path);
	printf("SO = %s\n", data->textures->SO_path);
	printf("WE = %s\n", data->textures->WE_path);
	printf("EA = %s\n", data->textures->EA_path);
}
