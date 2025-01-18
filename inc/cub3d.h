/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 16:18:03 by mjameau          ###   ########.fr       */
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

typedef struct s_line
{
	int			x;
	int			y;
	int			y0;
	int			y1;
	int			tex_x;
	int			tex_y;
}				t_line;

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

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
	int			img_size;
}				t_textures;

typedef struct s_player
{
	double		px;
	double		py;
	t_coord		dir_vect;
	t_coord		cam_plane_vect;
	double		cam_height;
	double		speed;
	double		sens;
}				t_player;

typedef struct s_image
{
	void		*img_ptr;
	char		*data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_ray
{
	int			curr_x;
	int			map_x;
	int			map_y;
	double		cam_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		prep_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

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
	t_player	*player;
	t_ray		*ray;
}				t_data;

// INIT
void			init_data(t_data *data);
void			set_player_pos(t_data *data);
void			init_mlx(t_data *data);
void			init_textures(t_data *data);

// RENDER AFFICHAGE ET CO
int				render(void *arg);
void			raytracing(t_data *data, t_ray *ray);
void			prep_height(t_ray *ray, t_player *player);

// MAP
void			load_map(t_data *data, char *map);
char			**malloc_map(char *map, t_data *data);
void			check_map(t_data *data);
void			get_map_info(t_data *data, char *map);
bool			is_map_start(char *str);
void			get_floor_ceiling(t_data *data);
void			display_map(t_data *data);

// SAFE FUNCTIONS
int				safe_open_fd(char *file, int flag, t_data *data);
void			*malloc_fd(size_t bytes, t_data *data, int *fd);

// UTILS
int				check_extension(const char *big, const char *little,
					size_t len);
int				count_strings(char **strings);
char			*strdup_without_n(const char *s);
bool			is_space(char c);

// INPUTS
int				handle_input(int keysym, t_data *data);

// FREE
void			err_msg(char *str, t_data *data, bool to_free);
void			free_textures(t_data *data);
void			free_tab(char **tab);
int				free_all(t_data *data, int exit_status);
void			debug(t_data *data);

#endif
