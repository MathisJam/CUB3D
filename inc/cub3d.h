/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/15 11:22:32 by mjameau          ###   ########.fr       */
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

# define FOV 60               // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4       // player speed

# define RST "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[5;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

enum			e_textures
{
	NO,
	EA,
	SO,
	WE,
	F,
	C
};

typedef struct s_textures
{
	void		*NO;
	void		*EA;
	void		*SO;
	void		*WE;
	char		*NO_path;
	char		*WE_path;
	char		*EA_path;
	char		*SO_path;
	char		**F_strings;
	char		**C_strings;
	int			*F;
	int			*C;
}				t_textures;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;

	int			x;
	int			y;
	int			row_nbr;
	int			column_nbr;
	int			map_start;
	int			player_x;
	int			player_y;
	int			next_x;
	int			next_y;

	char		**map;
	t_textures	*textures;
}				t_data;

// INIT
void			initialize(t_data *data);
void			get_floor_ceiling(t_data *data);
void			set_player_pos(t_data *data);

// MAP
void			load_map(t_data *data, char *map);
char			**malloc_map(char *map, t_data *data);
void			check_map(t_data *data);
void			get_map_info(t_data *data, char *map);
bool			is_map_start(char *str);

// SAFE FUNCTIONS
int				safe_open_fd(char *file, int flag, t_data *data);
void			*safe_malloc(size_t bytes, t_data *data);

// FREE & UTILS
int				check_extension(const char *big, const char *little,
					size_t len);
void			err_msg(char *str, t_data *data, bool to_free);
void			free_textures(t_data *data);
void			free_tab(char **tab);
int				free_all(t_data *data, int exit_status);
int				count_strings(char **strings);

void			debug(t_data *data);

#endif
