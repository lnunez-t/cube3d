/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 06:32:17 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/06 07:00:15 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
void	ft_init_name(t_data *data)
{
	data->name.maps = malloc(1 * sizeof(char *));
	if (!data->name.maps)
		exit (1);
	data->name.maps[0] = NULL;
	//data->name.maps[1] = NULL;
}
