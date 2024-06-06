/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:19:43 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/06 09:12:07 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_parse_first(char *line, int *i, t_data *data)
{
	if (line[0] == '\n')
		return ;
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		data->name.no = ft_strdup(&line[3]);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		data->name.so = ft_strdup(&line[3]);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		data->name.we = ft_strdup(&line[3]);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->name.ea = ft_strdup(&line[3]);
	else if (line[0] == 'F' && line[1] == ' ')
		data->name.f = ft_split(&line[2], ',');
	else if (line[0] == 'C' && line[1] == ' ')
		data->name.c = ft_split(&line[2], ',');
	else
	{
		ft_printf_error("ERREUR AVEC INTRUCTION DANS LA MAPS");
		exit(EXIT_FAILURE);
	}
	(*i)++;
}

int	ft_size_maps(t_data *data)
{
	int	i;

	i = 0;
	if (data->name.maps == NULL || data->name.maps[0] == NULL)
		return (0);
	while (data->name.maps[i])
		i++;
	return (i);
}

void	ft_parse_map(char *line, t_data *data, int *k)
{
	int		i;
	char	**m;

	if (line[0] == '\n' && (*k) != -10)
		return ;
	(*k) = -10;
	i = ft_size_maps(data);
	m = malloc((i + 3) * sizeof(char *));
	if (!m)
		exit(1);
	i = 0;
	while (data->name.maps && data->name.maps[i])
	{
		m[i] = ft_strdup(data->name.maps[i]);
		i++;
	}
	m[i] = ft_strdup(line);
	i++;
	m[i] = NULL;
	free_tab(data->name.maps);
	data->name.maps = m;
}

void	ft_parse(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i < 6 && i > -1)
			ft_parse_first(line, &i, data);
		else
			ft_parse_map(line, data, &i);
		free(line);
		line = get_next_line(fd);
	}
	// printf("le NO : %s\n",data->name.no);
	// printf("le SO : %s\n",data->name.so);
	// printf("le WE : %s\n",data->name.we);
	// printf("le EA : %s\n",data->name.ea);
	// for(int i = 0; data->name.f[i];i++)
	// {
	// 		printf("le F : %s\n",data->name.f[i]);
	// }
	// for(int i = 0; data->name.f[i];i++)
	// {
	// 		printf("le C : %s\n",data->name.c[i]);
	// }
	// for(int i = 0; data->name.maps[i];i++)
	// {
	// 	printf("maps : %s",data->name.maps[i]);
	// }
}

int	ft_open(char *name, t_data *data)
{
	int	fd;
	ft_init_name(data);
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf_error("PROBLEME AVEC L OPEN DU FICHIER\n");
		return (EXIT_FAILURE);
	}
	ft_parse(fd, data);
	ft_verif_maps(data);
	return (EXIT_SUCCESS);
}
