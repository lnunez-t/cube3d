/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_maps3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:41:51 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/07 18:42:31 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_replace_carac(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == ' ' || map[i][k] == '\t' || map[i][k] == '\n')
				map[i][k] = '2';
			if (map[i][k] == 'N' || map[i][k] == 'W' || map[i][k] == 'S'
				|| map[i][k] == 'E')
				map[i][k] = '0';
			k++;
		}
		i++;
	}
}

int	ft_verif_maps_chemin(char **maps, int i)
{
	char	**map_t;

	map_t = malloc((i + 3) * sizeof(char *));
	if (!map_t)
		exit(1);
	map_t[0] = ft_first_line(maps, 0);
	i = 0;
	while (maps[i])
	{
		map_t[i + 1] = ft_replace_line(maps[i], ft_strlen_max(maps));
		i++;
	}
	map_t[i + 1] = ft_first_line(maps, i - 1);
	map_t[i + 2] = NULL;
	ft_replace_carac(map_t);
	if (ft_verif_main(map_t) == 1)
	{
		ft_printf_error("PROBLEME AVEC LA MAPS MAL FERMER\n");
		free_tab(map_t);
		return (1);
	}
	free_tab(map_t);
	return (0);
}
