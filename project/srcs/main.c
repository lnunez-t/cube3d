/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:20:38 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/03 13:48:45 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int ac, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->map.player.x = 22; //x start position
	data->map.player.y = 12; //y start position
	data->map.player.dir_x = -1;
	data->map.player.dir_y = 0;
	data->map.player.plane_x = 0;
	data->map.player.plane_y = 0.66;
	data->map.player.time = 0;
	data->map.player.old_time = 0;
	init_map(data, argv[1]);
	render_window(data);
	render_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_window, data);
	mlx_loop(data->mlx_ptr);
	ft_free(data);
}
