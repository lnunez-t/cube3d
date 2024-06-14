/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:19:43 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/11 13:22:21 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_parse_first(char *line, int *i, t_data *data, int fd)
{
	if (line[0] == '\n')
		return ;
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		data->tex.no = eeee(&line[3]);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		data->tex.so = eeee(&line[3]);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		data->tex.we = eeee(&line[3]);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->tex.ea = eeee(&line[3]);
	else if (line[0] == 'F' && line[1] == ' ')
		data->tex.floor = get_rgb(&line[2]);
	else if (line[0] == 'C' && line[1] == ' ')
		data->tex.ceiling = get_rgb(&line[2]);
	else
	{
		ft_printf_error("%s\n", ERR_INFO_MAP);
		while (line)
		{
			free(line);
			line = get_next_line(fd, 0);
		}
		ft_end(data, 1);
	}
	(*i)++;
}

int	ft_size_maps(t_data *data)
{
	int	i;

	i = 0;
	if (data->tex.maps == NULL || data->tex.maps[0] == NULL)
		return (0);
	while (data->tex.maps[i])
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
	while (data->tex.maps && data->tex.maps[i])
	{
		m[i] = ft_strdup(data->tex.maps[i]);
		i++;
	}
	m[i] = ft_strdup(line);
	i++;
	m[i] = NULL;
	free_tab(data->tex.maps);
	data->tex.maps = m;
	data->map_info.all = m;
	data->map_info.rows = count_rows(data);
	data->map_info.cols = ft_strlen_max(data->map_info.all) - 1;
}

void	ft_parse(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		if (i < 6 && i > -1)
			ft_parse_first(line, &i, data, fd);
		else
			ft_parse_map(line, data, &i);
		free(line);
		line = get_next_line(fd, 0);
		if (!line)
		{
			get_next_line(0, 1);
			return ;
		}
	}
}

int	ft_open(char *name, t_data *data)
{
	int	fd;

	ft_init_name(data);
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		free_tab(data->tex.maps);
		ft_printf_error("%s\n", ERR_OPEN_FILE);
		return (EXIT_FAILURE);
	}
	ft_parse(fd, data);
	if (ft_verif_maps(data, fd) == 1)
	{
		free(data->tex.ceiling);
		free(data->tex.floor);
		free(data->tex.ea);
		free(data->tex.no);
		free(data->tex.we);
		free(data->tex.so);
		if(data->map_info.all)
			free_tab(data->map_info.all);
		else
			free(data->tex.maps);
		return (1);
	}
	return (EXIT_SUCCESS);
}
