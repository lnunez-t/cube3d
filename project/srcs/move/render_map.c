/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:49:00 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/20 15:38:42 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	which_sprite(t_data *data, int y, int x)
{
	char	px;

	px = data->map.all[y][x];
	if (px == W)
		render_sprite(data, data->wall, y, x);
	else if (px == F)
		render_sprite(data, data->floor, y, x);
	else if (px == C)
		render_sprite(data, data->sky, y, x);
}

void	render_sprite(t_data *data, t_img sprite, int y, int x)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite.xpm_img,
		x * sprite.x, y * sprite.y);
}

void	render_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, WIN_TITLE);
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		ft_putstr_fd("Couldn't create the window.", 1);
	}
}
