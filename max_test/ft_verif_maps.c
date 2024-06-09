/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:14:14 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/07 18:42:28 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_strlen_max(char **map)
{
	int	k;
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
			k++;
		if (k > result)
			result = k;
		i++;
	}
	return (result);
}

int	ft_verif_maps_carac(char **maps)
{
	int	i;
	int	k;

	i = 0;
	while (maps[i])
	{
		k = 0;
		while (maps[i][k])
		{
			if (maps[i][k] != '1' && maps[i][k] != '0' && maps[i][k] != 'N'
				&& maps[i][k] != 'S' && maps[i][k] != 'W' && maps[i][k] != 'E'
				&& maps[i][k] != '\n' && maps[i][k] != ' '
				&& maps[i][k] != '\t')
			{
				ft_printf_error("PROBLEME AVEC LA MAPS IL Y A UN '%c'\n",
					maps[i][k]);
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

char	*ft_first_line(char **maps, int k)
{
	int		i;
	char	*dest;

	i = ft_strlen_max(maps);
	dest = malloc((i + 2) * sizeof(char));
	if (!dest)
		exit(1);
	dest[i + 1] = '\0';
	while (i > -1)
	{
		dest[i] = '2';
		i--;
	}
	return (dest);
}

char	*ft_replace_line(char *src, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((end + 3) * sizeof(char));
	if (!dest)
		exit(1);
	dest[0] = '2';
	while (src[i])
	{
		dest[i + 1] = src[i];
		i++;
	}
	if (src[i] == '\0')
	{
		i++;
	}
	while (i <= end)
	{
		dest[i] = '2';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



int	ft_verif_maps(t_data *data)
{
	if (ft_verif_maps_carac(data->name.maps) == 1)
		return (1);
	if (ft_verif_maps_chemin(data->name.maps, ft_size_maps(data)) == 1)
		return (1);
	return (0);
}
