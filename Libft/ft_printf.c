/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:42:38 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/18 19:58:19 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	formating(va_list args, const char format, int *res)
{
	if (format == 's')
		ft_putstr_fd2(va_arg(args, char *), res);
	else if (format == 'c')
		ft_putchar_fd2(va_arg(args, int), res);
	else if ((format == 'd' || format == 'i'))
		ft_putnbr_fd2(va_arg(args, int), res);
	else if (format == 'p')
		to_hex (va_arg(args, unsigned long), res);
	else if (format == 'x' || format == 'X')
		deci_hex(va_arg(args, unsigned long), res, format);
	else if (format == 'u')
		ft_putunsi_fd(va_arg(args, unsigned int), res);
	else
		ft_putchar_fd2(format, res);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			res;
	va_list		args;

	va_start(args, format);
	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			formating(args, format[i], &res);
		}
		else if (format[i] != '%')
			ft_putchar_fd2(format[i], &res);
		i++;
	}
	va_end(args);
	return (res);
}
