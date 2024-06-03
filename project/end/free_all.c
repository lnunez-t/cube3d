/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:50:52 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/20 15:53:03 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_free(t_data *data)
{
	destroy_sprites(data);
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

void	destroy_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->floor.xpm_img);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
		free(data->map.all[i++]);
	free(data->map.all);
}
