/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:53 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/10 18:33:26 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static bool	valid_pos_map(t_data *data, double x, double y)
{
	if (x < 1.25 || x >= data->map_info.cols - 1.25)
		return (false);
	if (y < 1.25 || y >= data->map_info.rows - 1.25)
		return (false);
	return (true);
}

static bool	valid_pos(t_data *data, double x, double y)
{
	if (valid_pos_map(data, x, y) == true)
		return (true);
	return (false);
}

int	valid_move(t_data *data, double new_posx, double new_posy)
{
	int	move;

	move = 0;
	if (valid_pos(data, new_posx, new_posy) == true)
	{
		data->player.pos_x = new_posx;
		data->player.pos_y = new_posy;
		move = 1;
	}
	return (move);
}
