/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:44:18 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/10 17:05:52 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	find_player(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map_info.all;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				data->player.dir = map[i][j];
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

int	camera_move(t_data *data, double rotspeed)
{
	t_player	*player;
	double		tmp;

	player = &data->player;
	tmp = player->dir_x;
	player->dir_x = player->dir_x * cos(rotspeed) - player->dir_y
		* sin(rotspeed);
	player->dir_y = tmp * sin(rotspeed) + player->dir_y * cos(rotspeed);
	tmp = player->plane_x;
	player->plane_x = player->plane_x * cos(rotspeed) - player->plane_y
		* sin(rotspeed);
	player->plane_y = tmp * sin(rotspeed) + player->plane_y * cos(rotspeed);
	return (1);
}

int	player_move(t_data *data)
{
	int	move;

	move = 0;
	if (data->player.move_y == 1)
		move += move_up(data);
	if (data->player.move_y == -1)
		move += move_down(data);
	if (data->player.move_x == -1)
		move += move_left(data);
	if (data->player.move_x == 1)
		move += move_right(data);
	if (data->player.rotate != 0)
		move += rotate_player(data, data->player.rotate);
	return (move);
}

int	render(t_data *data)
{
	data->player.has_moved += player_move(data);
	if (data->player.has_moved == 0)
		return (0);
	render_map(data);
	return (0);
}
