/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_maps2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:21:34 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/11 13:23:13 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_max_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_verif_main(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0)
		{
			if (ft_verif_first(map) == 1)
				return (1);
		}
		else if (i == ft_max_line(map) - 1)
		{
			if (ft_verif_last(map, ft_max_line(map) - 1) == 1)
				return (1);
		}
		else
		{
			if (ft_verif_mid(map, i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_verif_first(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[1][i] != '2' && map[1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_verif_mid(char **map, int k)
{
	int	i;

	i = 0;
	while (map[k][i])
	{
		if (map[k][i] == '2' && map[k - 1][i] != '2' && map[k - 1][i] != '1')
			return (1);
		if (map[k][i] == '2' && map[k + 1][i] != '2' && map[k + 1][i] != '1')
			return (1);
		if (map[k][i] == '2' && map[k][i + 1] != '2' && map[k][i + 1] != '1'
			&& map[k][i + 1] != '\0')
			return (1);
		if (i != 0 && map[k][i] == '2' && map[k][i - 1] != '2' && map[k][i
			- 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_verif_last(char **map, int k)
{
	int	i;

	i = 0;
	while (map[k][i])
	{
		if (map[k - 1][i] != '2' && map[k - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}
