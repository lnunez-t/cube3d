/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:07:45 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/03 14:02:46 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	handle_input(int keysym, t_data *data)
{
	while (1)
	{
		raycaster(data);
		if (keysym == KEY_UP || keysym == KEY_W)
			player_move(data, data->map.player.y - 1, data->map.player.x, UP);
		if (keysym == KEY_DOWN || keysym == KEY_S)
			player_move(data, data->map.player.y + 1, data->map.player.x, DOWN);
		if (keysym == KEY_LEFT || keysym == KEY_A)
			player_move(data, data->map.player.y, data->map.player.x - 1, LEFT);
		if (keysym == KEY_RIGHT || keysym == KEY_D)
			player_move(data, data->map.player.y, data->map.player.x + 1,
				RIGHT);
		if (keysym == KEY_Q || keysym == KEY_ESC)
			close_window(data);
	}
	return (0);
}

void	player_move_up(t_data *data, double speed)
{

}
