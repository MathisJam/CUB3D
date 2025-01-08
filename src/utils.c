/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:44:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/08 11:46:40 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	is_starting_row(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 1)
		return (false);
	while (str && (str[i] == '1' || str[i] == ' '))
		i++;
	if (str[i] == '\n')
		return (true);
	return (false);
}

int	starting_row(char *str, t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	int		start;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	fd = safe_open_fd(str, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		j = 0;
		while (line && (line[j] == '1' || line[j] == ' '))
			j++;
		if (j > 1 && (line[j] == '\n'))
		{
			start = i;
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (start);
}

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

void	err_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
}

int	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (data == NULL)
		return (1);
	if (data->sprite[0])
	{
		while (++i <= 3)
		{
			if (data->sprite[i])
				mlx_destroy_image(data->mlx_ptr, data->sprite[i]);
		}
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
	exit(0);
}
