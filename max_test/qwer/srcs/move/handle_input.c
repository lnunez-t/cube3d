/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:07:45 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/09 11:18:21 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	handle_keysym(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_Left)
		data->player.rotate -= 1;
	if (keysym == XK_Right)
		data->player.rotate += 1;
	if (keysym == XK_w)
		data->player.move_y = 1;
	if (keysym == XK_a)
		data->player.move_x = -1;
	if (keysym == XK_s)
		data->player.move_y = -1;
	if (keysym == XK_d)
		data->player.move_x = 1;
	return (0);
}

int	release_keysym(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (keysym == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	if (keysym == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (keysym == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (keysym == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (keysym == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	return (0);
}

void	handle_input(t_data *data)
{
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keysym, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, release_keysym, data);
}
