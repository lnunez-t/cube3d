/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:28:06 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/03 16:11:47 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// int	count_rows(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->map.all[i])
// 		i++;
// 	return (i);
// }

// char	*check_empty_line(char *map, t_data *data)
// {
// 	int		i;
// 	char	*new;

// 	i = 0;
// 	new = NULL;
// 	if (map[0] == '\n' || map[ft_strlen(map)] == '\n')
// 	{
// 		new = ft_strtrim(map, "\n");
// 		while (new[i] && new[i + 1])
// 		{
// 			if (new[i] == '\n' && new[i + 1] == '\n')
// 			{
// 				ft_putstr_fd("Empty line in the map", 1);
// 				free(new);
// 				free_data(data);
// 			}
// 			i++;
// 		}
// 		free(map);
// 	}
// 	else
// 		new = map;
// 	return (new);
// }

// void	init_map(t_data *data, char *argv)
// {
// 	char	*map_temp;
// 	char	*line_temp;
// 	int		map_fd;
// 	int		i;
// 	int		map_begin;

// 	i = 0;
// 	map_begin = 1;
// 	map_fd = open(argv, O_RDONLY);
// 	if (map_fd == -1)
// 	{
// 		ft_putstr_fd("Map could not be opened.", 1);
// 		free(data);
// 		exit(EXIT_FAILURE);
// 	}
// 	map_temp = ft_strdup("");
// 	line_temp = get_next_line(map_fd);
// 	while (line_temp)
// 	{
// 		i = 0;
// 		while (line_temp[i])
// 		{
// 			if (ft_strrchr("NSWEFC", line_temp[i]))
// 			{
// 				map_begin = 0;
// 				break ;
// 			}
// 			i++;
// 		}
// 		if (map_begin)
// 			map_temp = ft_strappend(map_temp, line_temp);
// 		free(line_temp);
// 		line_temp = get_next_line(map_fd);
// 	}
// 	close(map_fd);
// 	free(line_temp);
// 	map_temp = check_empty_line(map_temp, data);
// 	data->map.all = ft_split(map_temp, '\n');
// 	free(map_temp);
// 	data->map.rows = count_rows(data);
// 	data->map.cols = ft_strlen(data->map.all[0]) - 1;
// }

void	init_test(t_data *data)
{
	char	all[8][25] = {"111111111111111111111111\0", "100000000000000000000001\0", "100000000000000000000001\0", "100000000000000000000001\0", "100000111110000101010001\0", "100000100010000000000001\0", "111111111111111111111111\0", 0};

	data->map.all = malloc(8 * sizeof(char *));
	if (!data->map.all)
	{
		return ;
	}
	for (size_t i = 0; i < 8; i++)
	{
		data->map.all[i] = ft_strdup(all[i]);
	}
}

int main(void)
{
	t_data data;

	init_test(&data);

	for (size_t i = 0; i < 8; i++)
	{
		printf("data->map [%ld] : %s\n", i, data.map.all[i]);
	}

	return 0;
}

