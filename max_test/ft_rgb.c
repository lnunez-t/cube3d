/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 06:40:47 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/07 18:37:37 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_rgb_first(t_data *data)
{
	int	i;

	i = 0;
	while (data->name.f[i])
	{
		if (data->name.f[i][0] > '9' || data->name.f[i][0] < '0')
			return (1);
		i++;
	}
	if (ft_max_line(data->name.c) != 3 || ft_max_line(data->name.f) != 3
		|| data->name.f[2][0] == '\0' || data->name.c[2][0] == '\0')
		return (1);
	return (0);
}

int	ft_rgb(t_data *data)
{
	int	i;

	i = 0;
	if (ft_rgb_first(data) == 1)
		return (1);
	while (i < 3)
	{
		data->name.final_c[i] = ft_atoi(data->name.c[i]);
		data->name.final_f[i] = ft_atoi(data->name.f[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (ft_strlen(data->name.c[i]) > 8 || ft_strlen(data->name.c[i]) < 0
			|| data->name.final_c[i] < 0 || data->name.final_c[i] > 255)
			return (1);
		if (ft_strlen(data->name.f[i]) > 8 || ft_strlen(data->name.f[i]) < 0
			|| data->name.final_f[i] < 0 || data->name.final_f[i] > 255)
			return (1);
		i++;
	}
	return (0);
}
