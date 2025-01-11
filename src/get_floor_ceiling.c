/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:59:52 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/11 12:53:37 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	atoi_skip_alpha(const char *s)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((9 <= s[i]) && (s[i]) <= 13) || (s[i] == 32) || ft_isalpha(s[i]))
		i++;
	if ((s[i] == '+') || (s[i] == '-'))
	{
		if (s[i] == '+')
			i++;
		else
		{
			sign *= -1;
			i++;
		}
	}
	while (('0' <= s[i]) && (s[i] <= '9'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int	count_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings && strings[count])
		count++;
	return (count);
}

static int	*convert_to_int_arr(char **tab)
{
	int	i;
	int	count;
	int	*arr;

	i = -1;
	count = count_strings(tab);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	while (++i < count)
	{
		if (tab[i])
			arr[i] = atoi_skip_alpha(tab[i]);
		else
			arr[i] = 0;
	}
	return (arr);
}

void	get_floor_ceiling(t_data *data)
{
	data->textures->C = convert_to_int_arr(data->textures->C_strings);
	data->textures->F = convert_to_int_arr(data->textures->F_strings);
}
