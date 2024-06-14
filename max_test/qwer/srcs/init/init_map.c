/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:28:06 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/11 12:36:33 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_init_name(t_data *data)
{
	data->tex.maps = malloc(1 * sizeof(char *));
	if (!data->tex.maps)
		ft_end(data, 1);
	data->tex.maps[0] = NULL;
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (free(s1), NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	str[ft_strlen(str)] = '\0';
	free(s1);
	return (str);
}

int	count_rows(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_info.all[i])
		i++;
	return (i);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf_error(ERR_MLX_PTR);
		ft_end(data, 1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, WIN_TITLE);
	if (data->win_ptr == NULL)
	{
		ft_printf_error(ERR_WIN);
		ft_end(data, 1);
	}
	return ;
}
