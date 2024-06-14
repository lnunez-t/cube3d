/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:29:19 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/11 13:19:29 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, int flag)
{
	char		*buffer;
	int			nbyte;
	static char	*temp;

	nbyte = 1;
	if (flag)
		return (free(temp), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (free(buffer), NULL);
		buffer[nbyte] = 0;
		temp = ft_strj(temp, buffer);
		if (is_n(temp))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&temp));
}
