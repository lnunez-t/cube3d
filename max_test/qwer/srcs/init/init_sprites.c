/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:22:36 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/09 14:36:38 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;

	int (y) = 0;
	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->tex.size * data->tex.size);
	if (!buffer)
	{
		ft_printf_error(ERR_MALLOC);
		ft_end(data, 1);
	}
	while (++y < data->tex.size)
	{
		x = 0;
		while (x < data->tex.size)
		{
			buffer[y * data->tex.size + x]
				= tmp.addr[y * data->tex.size + x];
			++x;
		}
	}
	mlx_destroy_image(data->mlx_ptr, tmp.xpm_img);
	return (buffer);
}

void	init_sprites(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
	{
		ft_printf_error("%s\n", ERR_MALLOC);
		ft_end(data, 1);
	}
	data->textures[NORTH] = xpm_to_img(data, data->tex.no);
	data->textures[SOUTH] = xpm_to_img(data, data->tex.so);
	data->textures[EAST] = xpm_to_img(data, data->tex.ea);
	data->textures[WEST] = xpm_to_img(data, data->tex.we);
}

void	init_texinfo(t_name *textures)
{
	textures->no = NULL;
	textures->so = NULL;
	textures->we = NULL;
	textures->ea = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->xpm_img = mlx_new_image(data->mlx_ptr, width, height);
	if (image->xpm_img == NULL)
	{
		ft_printf_error(ERR_MLX_PTR);
		ft_end(data, 1);
	}
	image->addr = (int *)mlx_get_data_addr(image->xpm_img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->xpm_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->tex.size,
			&data->tex.size);
	if (image->xpm_img == NULL)
	{
		ft_printf_error(ERR_MLX_PTR);
		ft_end(data, 1);
	}
	image->addr = (int *)mlx_get_data_addr(image->xpm_img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}
