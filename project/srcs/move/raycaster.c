/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:05:59 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/20 16:45:20 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	raycaster(t_data *data)
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	frame_time;
	int		step_x;
	int		step_y;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;

	int (x) = 0;
	int (hit) = 0;
	int (map_x) = data->map.player.x;
	int (map_y) = data->map.player.y;
	double (w) = data->map.cols;
	double (h) = data->map.rows;
	double (dir_x) = data->map.player.dir_x;
	double (plane_x) = data->map.player.plane_x;
	double (dir_y) = data->map.player.dir_y;
	double (plane_y) = data->map.player.plane_y;

	while (x < w)
	{
		camera_x = 2 * x / w - 1;
		raydir_x = dir_x + plane_x * camera_x;
		raydir_y = dir_y + plane_y * camera_x;
		if (raydir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = abs(1 / raydir_x);
		if (raydir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = abs(1 / raydir_y);
		if (raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->map.player.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->map.player.x) * delta_dist_x;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->map.player.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->map.player.y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
		}
		if (data->map.all[map_x][map_y] > 0)
			hit = 1;
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_x - delta_dist_x;
		line_h = (int)(h / perp_wall_dist);
		draw_start = -line_h / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_h / 2 + h / 2;
		if (draw_end >= h)
			draw_end = h - 1;
		x++;
	}
	data->map.player.old_time = data->map.player.time;
	data->map.player.time = millitimestamp();
	frame_time = (data->map.player.time - data->map.player.old_time) / 1000.0;
}

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}
