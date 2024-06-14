/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:20:38 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/10 17:47:34 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_info.all[i])
	{
		j = 0;
		while (data->map_info.all[i][j])
		{
			printf("%c", data->map_info.all[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf_error("%s\n", ERR_ARGS);
		return (EXIT_FAILURE);
	}
	init_data(&data);
	if (parsing(argv[1], &data) == 1)
		return (EXIT_FAILURE);
	if (check_textures(&data.tex) == 1)
		ft_end(&data, 1);
	find_player(&data);
	init_dir(&data);
	init_mlx(&data);
	init_sprites(&data);
	render_map(&data);
	handle_input(&data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
