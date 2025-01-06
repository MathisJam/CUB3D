/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/06 14:54:24 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>

# define PI 3.1415926535 // 180 degres (a gauche)
# define P0 6.283185307 // PI*2 -> 0 ou 360 degres (a droite)
# define P2 1.57079632679 // PI/2 -> 90 degres (en haut)
# define P3 4.71238898038 // 3*PI/2 -> 270 degres (en bas)

typedef struct s_window
{
	void	*ptr;
	void	*window;
	int		win_size;
}		t_window;

typedef struct s_data
{
	int			x;
	int			y;
	int			player_x;
	int			player_x;
	int			next_x;
	int			next_y;
	char		**map;
	t_window	*window;
}		t_data;

#endif
