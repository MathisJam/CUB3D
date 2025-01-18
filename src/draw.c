/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:21:28 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/18 16:33:09 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	pixel_on_img(int rgb, int x, int y, t_image *img)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8] = b;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 1] = g;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 2] = r;
}

void	draw_texture_image(t_data *data, t_ray *ray, t_line *line, t_image *img)
{
	int	y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		line->y--;
		while (++line->y < y_max)
			texture_on_img(data, ray, line, img);
	}
}

void	paint_line(t_data *data, t_line *line, int rgb)
{
	int	y;
	int	y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_on_img(rgb, line->x, y, data->textures);
			y++;
		}
	}
}
