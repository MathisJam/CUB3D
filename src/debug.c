/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:12:15 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/19 16:26:21 by jchen            ###   ########.fr       */
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
	count = count_strings(data->F_strings);
	if (data->F)
	{
		printf("Tableau d'entiers F : ");
		for (int i = 0; i < count; i++)
		{
			printf("%d ", data->F[i]);
		}
		printf("\n");
	}
	count = count_strings(data->C_strings);
	if (data->C)
	{
		printf("Tableau d'entiers C : ");
		for (int i = 0; i < count; i++)
		{
			printf("%d ", data->C[i]);
		}
		printf("\n");
	}
	printf("Player x = %f\nPlayer y = %f\n", data->player->px,
		data->player->py);
	printf("NO = %s\n", data->NO->path);
	printf("SO = %s\n", data->SO->path);
	printf("WE = %s\n", data->WE->path);
	printf("EA = %s\n", data->EA->path);
}
