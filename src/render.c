/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:52:01 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 16:32:44 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static void	load_texture(t_data *data, t_image *img, char *path)
// {
// 	int	width;
// 	int	height;

// 	width = 64;
// 	height = 64;
// 	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
// 	if (!img->img_ptr)
// 		err_msg("mlx_xpm_file_to_image() failure\n", data, true);
// 	img->width = width;
// 	img->height = height;
// 	img->data = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
// 			&img->line_length, &img->endian);
// }

static void	paint_texture_line(t_data *data, t_ray *ray, t_line *line,
		double wall_x)
{
	t_image	*img;
	int		tex_x;

	img = data->textures->NO;
	if (ray->side == EA)
		img = data->textures->EA;
	else if (ray->side == WE)
		img = data->textures->WE;
	else if (ray->side == NO)
		img = data->textures->NO;
	else if (ray->side == SO)
		img = data->textures->SO;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == WE || ray->side == EA) && ray->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->side == NO || ray->side == SO) && ray->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_start;
	line->y1 = ray->draw_end;
	line->tex_x = tex_x;
	draw_texture_image(data, ray, line, img);
}

void	draw_textures(t_data *data, t_ray *ray, t_player *player)
{
	t_line	*line;
	double	wall_x;

	line = malloc(sizeof(t_line));
	ft_bzero(line, sizeof(t_line));
	if (ray->side == WE || ray->side == EA)
		wall_x = player->py + ray->prep_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->py + ray->prep_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	line->x = ray->curr_x;
	if (data->map[ray->map_y][ray->map_x] == '1')
		paint_texture_line(data, ray, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	paint_line(data, line, data->textures->C);
	line->y0 = 1080;
	line->y1 = ray->draw_end;
	paint_line(data, line, data->textures->F);
	free(line);
}

int	render(void *arg)
{
	t_data	*data;
	t_ray	*ray;

	data = (t_data *)arg;
	ray = malloc(sizeof(t_ray));
	ft_bzero(ray, sizeof(t_ray));
	while (ray->curr_x < 1920)
		raytracing(data, ray);
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
	// 	data->mlx_img->img_ptr, 0, 0);
	free(ray);
	// si on veut mettre event handler
	return (0);
}
