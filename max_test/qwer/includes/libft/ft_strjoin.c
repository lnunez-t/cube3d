/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:26:19 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/06 17:20:22 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	size_t (i) = 0;
	int (len) = ft_strlen(s2);
	if (!s1)
	{
		if (!s2)
			return (NULL);
		else
			return (ft_strdup(s2));
	}
	else if (s1 && !s2)
		return (ft_strdup(s1));
	len = len + ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	len = 0;
	while (s1[i])
		s[len++] = s1[i++];
	i = 0;
	while (s2[i])
		s[len++] = s2[i++];
	s[len] = '\0';
	return (s);
}
