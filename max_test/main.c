/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:15:19 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/06 07:55:20 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft/libft.h"

// pour les test

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

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
int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_printf_error("PROBLEME AVEC LES ARGUMENT\n");
		return (EXIT_FAILURE);
	}
	if (verif_path(av[1]) == 1)
	{
		ft_printf_error("ERREUR AVEC LE PATH : %s\n",av[1]);
		return (EXIT_FAILURE);
	}
	if (ft_open(av[1], &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_end(&data);
	return (EXIT_SUCCESS);

}
