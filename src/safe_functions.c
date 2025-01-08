/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:00:14 by jchen             #+#    #+#             */
/*   Updated: 2025/01/08 16:44:38 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	safe_open_fd(char *file, int flag, t_data *data)
{
	int	fd;

	fd = open(file, flag);
	if (fd < 0)
		err_msg("Failed to open fd\n", data, true);
	return (fd);
}

void	*safe_malloc(size_t bytes, t_data *data)
{
	void	*allocation;

	allocation = malloc(bytes);
	if (!allocation)
		err_msg("Malloc failed\n", data, true);
	return (allocation);
}
