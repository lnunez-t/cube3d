/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:56:09 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/06 08:00:14 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_end(t_data *data)
{
	free(data->name.ea);
	free(data->name.no);
	free(data->name.so);
	free(data->name.we);
	free_tab(data->name.c);
	free_tab(data->name.f);
	free_tab(data->name.maps);
}
