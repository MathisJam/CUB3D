/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/08 12:36:47 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PI 3.1415926535  // 180 degres (a gauche)
# define P0 6.283185307   // PI*2 -> 0 ou 360 degres (a droite)
# define P2 1.57079632679 // PI/2 -> 90 degres (en haut)
# define P3 4.71238898038 // 3*PI/2 -> 270 degres (en bas)

# define RST "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[5;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

typedef enum sprites
{
	NO,
	EA,
	SO,
	WE
}			e_sprites;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;

	void	*sprite[3];
	char	**map;

	int		x;
	int		y;
	int		row_nbr;
	int		column_nbr;
	int		player_x;
	int		player_y;
	int		next_x;
	int		next_y;
}			t_data;

// INIT
void		initialize(t_data *data, char *argv);

// MAP
void		load_map(t_data *data, char *map);
char		**malloc_map(char *map, t_data *data);

// SAFE FUNCTIONS
int			safe_open_fd(char *file, int flag, t_data *data);
void		*safe_malloc(size_t bytes, t_data *data);

// FREE & UTILS
int			check_extension(const char *big, const char *little, size_t len);
void		err_msg(char *str);
int			free_all(t_data *data);
void		free_tab(char **tab);

#endif
