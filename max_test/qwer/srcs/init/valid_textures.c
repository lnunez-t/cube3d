/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:43:29 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/07 16:12:10 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			printf("%s\n", "INVALID RGB");
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned long	convert_hex(int *rgb)
{
	unsigned long	hex;
	int				r;
	int				g;
	int				b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (hex);
}

int	check_textures(t_name *tex)
{
	if (!tex->no || !tex->so || !tex->we || !tex->ea)
	{
		printf("%s\n", "TEXTURE MISSING");
		return (1);
	}
	if (!tex->floor || !tex->ceiling)
	{
		printf("%s\n", "COLOR MISSING");
		return (1);
	}
	if (valid_rgb(tex->floor) == 1 || valid_rgb(tex->ceiling) == 1)
		return (1);
	tex->hex_floor = convert_hex(tex->floor);
	tex->hex_ceiling = convert_hex(tex->ceiling);
	return (0);
}
