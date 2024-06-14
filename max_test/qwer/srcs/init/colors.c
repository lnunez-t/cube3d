/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:19:50 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/07 16:21:07 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static bool	find_digit(char *str)
{
	int		i;
	bool	is_digit;

	i = 0;
	is_digit = false;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			is_digit = true;
			break ;
		}
		i++;
	}
	return (is_digit);
}

int	*convert_rgb(char **char_rgb, int *rgb)
{
	int	i;

	i = 0;
	while (char_rgb[i])
	{
		rgb[i] = ft_atoi(char_rgb[i]);
		if (rgb[i] == -1 || find_digit(char_rgb[i]) == false)
		{
			free(rgb);
			free_tab(char_rgb);
			return (0);
		}
		i++;
	}
	free_tab(char_rgb);
	return (rgb);
}

int	*get_rgb(char *line)
{
	int		*rgb;
	int		count;
	char	**char_rgb;

	char_rgb = ft_split(line, ',');
	count = 0;
	while (char_rgb[count])
		count++;
	if (count != 3)
	{
		free_tab(char_rgb);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		printf("%s\n", "MALLOC ERROR");
		return (0);
	}
	return (convert_rgb(char_rgb, rgb));
}
