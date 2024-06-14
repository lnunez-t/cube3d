/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:31 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/10 16:45:24 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	verif_path_cub(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (i <= 4)
		return (EXIT_FAILURE);
	if (name[i - 4] == '.' && name[i - 3] == 'c' && name[i - 2] == 'u' && name[i
			- 1] == 'b')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	verif_path(char *name)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (name[i])
	{
		if (name[i] == '.')
		{
			count++;
			if (count > 1)
				return (EXIT_FAILURE);
		}
		i++;
	}
	if (verif_path_cub(name) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parsing(char *str, t_data *data)
{
	if (verif_path(str) == 1)
	{
		ft_printf_error("%s : %s\n", ERR_PATH, str);
		return (EXIT_FAILURE);
	}
	if (ft_open(str, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
