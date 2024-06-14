/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:27:57 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/09 14:31:21 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	free_textures(t_name *tex)
{
	if (tex->ea)
		free(tex->ea);
	if (tex->no)
		free(tex->no);
	if (tex->so)
		free(tex->so);
	if (tex->we)
		free(tex->we);
	if (tex->floor)
		free(tex->floor);
	if (tex->ceiling)
		free(tex->ceiling);
}

void	ft_free_all(t_data *data)
{
	if (data->textures)
		free_tab((char **)data->textures);
	if (data->texture_pixels)
		free_tab((char **)data->texture_pixels);
	free_textures(&data->tex);
	free_tab(data->tex.maps);
}

void	ft_end(t_data *data, int exit_code)
{
	if (!data)
		exit(exit_code);
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		mlx_loop_end(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_free_all(data);
	exit(exit_code);
}

int	close_window(t_data *data)
{
	ft_end(data, 0);
	return (0);
}
