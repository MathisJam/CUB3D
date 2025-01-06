/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/06 14:43:22 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define PI 3.1415926535 // 180 degres (a gauche)
# define P0 2*PI // 0 degres ou 360 degres (a droite)
# define P2 PI/2 // 90 degres (en haut)
# define P3 3*PI/2 // 270 degres (en bas)

typedef struct s_window
{
    void	*ptr;
    void    *window;
    int     win_size;
}	t_window;

typedef struct s_data
{
	int		x;
	int		y;
	int		player_x;
	int		player_x;
	int		next_x;
	int		next_y;
	char		**map;
	t_window	*window;

}   t_data;

#endif
