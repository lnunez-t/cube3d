/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:49:00 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/10 17:23:57 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->tex.hex_ceiling);
	else if (y < data->win_height - 1)
		set_image_pixel(image, x, y, data->tex.hex_floor);
}

static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.xpm_img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image.xpm_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image.xpm_img);
}

void	render_map(t_data *data)
{
	init_textures(data);
	init_ray(&data->ray);
	raycaster(&data->player, data);
	render_frame(data);
}
