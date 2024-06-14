/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:44:11 by matorgue          #+#    #+#             */
/*   Updated: 2024/06/09 11:33:24 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	check_fmt_error(const char *fmt, va_list args, int *len)
{
	if (*fmt == 's')
		ft_putstr_error(va_arg(args, char *), len);
	else if (*fmt == 'c')
		ft_putchar_error((char) va_arg(args, int), len);
	else if (*fmt == 'p')
		ft_putptr_error(va_arg(args, void *), len);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_dec_error(va_arg(args, int), len);
	else if (*fmt == 'u')
		ft_putnbr_un_error(va_arg(args, unsigned int), len);
	else if (*fmt == 'x')
		ft_putnbr_base_error(va_arg(args, unsigned int),
			HEX_LOW_FMT, len);
	else if (*fmt == 'X')
		ft_putnbr_base_error(va_arg(args, unsigned int),
			HEX_UP_FMT, len);
	else
		ft_putchar_error(*fmt, len);
}

int	ft_printf_error(const char *fmt, ...)
{
	int		len;
	va_list	args;

	len = 0;
	ft_putstr_fd("Error\n", 2);
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			check_fmt_error(fmt, args, &len);
		}
		else
			ft_putchar_error(*fmt, &len);
		fmt++;
	}
	va_end(args);
	return (len);
}
