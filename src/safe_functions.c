/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:00:14 by jchen             #+#    #+#             */
/*   Updated: 2025/01/07 14:04:10 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	safe_open_fd(char *file, int flag, t_data *data)
{
	int	fd;

	fd = open(file, flag);
	if (fd < 0)
	{
		err_msg("Failed to open fd\n");
		free_all(data);
	}
	return (fd);
}
