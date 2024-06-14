/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:39:57 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/07 14:11:40 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	move_up(t_data *data)
{
	double	new_posx;
	double	new_posy;

	new_posx = data->player.pos_x + data->player.dir_x * MOVESPEED;
	new_posy = data->player.pos_y + data->player.dir_y * MOVESPEED;
	return (valid_move(data, new_posx, new_posy));
}

int	move_down(t_data *data)
{
	double	new_posx;
	double	new_posy;

	new_posx = data->player.pos_x - data->player.dir_x * MOVESPEED;
	new_posy = data->player.pos_y - data->player.dir_y * MOVESPEED;
	return (valid_move(data, new_posx, new_posy));
}

int	move_left(t_data *data)
{
	double	new_posx;
	double	new_posy;

	new_posx = data->player.pos_x + data->player.dir_y * MOVESPEED;
	new_posy = data->player.pos_y - data->player.dir_x * MOVESPEED;
	return (valid_move(data, new_posx, new_posy));
}

int	move_right(t_data *data)
{
	double	new_posx;
	double	new_posy;

	new_posx = data->player.pos_x - data->player.dir_y * MOVESPEED;
	new_posy = data->player.pos_y + data->player.dir_x * MOVESPEED;
	return (valid_move(data, new_posx, new_posy));
}

int	rotate_player(t_data *data, double rotate)
{
	int		move;
	double	speed;

	move = 0;
	speed = ROTSPEED * rotate;
	move += camera_move(data, speed);
	return (move);
}
