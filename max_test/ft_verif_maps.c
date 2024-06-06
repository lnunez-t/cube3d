/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:14:14 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/06 14:34:32 by matorgue         ###   ########.fr       */
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
	// printf("\t%s\n",src);
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
			if (map[i][k] == ' ' || map[i][k] == '\t')
				map[i][k] = '2';
			if (map[i][k] == 'N' || map[i][k] == 'W' || map[i][k] == 'S' || map[i][k] == 'E')
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
	for (int k = 0; map_t[k]; k++)
	{
		printf("maps : %s\n", map_t[k]);
	}
	if (ft_verif_main(map_t) == 1)
	{
		ft_printf_error("PROBLEME AVEC LA MAPS MAL FERMER\n");
		return (1);
	}
	return (0);
}
int	ft_verif_maps(t_data *data)
{
	if (ft_verif_maps_carac(data->name.maps) == 1)
		return (1);
	if (ft_verif_maps_chemin(data->name.maps, ft_size_maps(data)) == 1)
		return (1);
	return (0);
}
