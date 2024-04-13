/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:47:46 by amejdoub          #+#    #+#             */
/*   Updated: 2024/02/21 19:16:19 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd2(int n, int *i)
{
	if (n == -2147483648)
		ft_putstr_fd2("-2147483648", i);
	else if (n < 0)
	{
		ft_putchar_fd2('-', i);
		ft_putnbr_fd2(-n, i);
	}
	else if (n < 10)
		ft_putchar_fd2(n + '0', i);
	else if (n >= 10)
	{
		ft_putnbr_fd2(n / 10, i);
		ft_putchar_fd2(n % 10 + '0', i);
	}
}

void	ft_putunsi_fd(unsigned int n, int *i)
{
	if (n < 10)
		ft_putchar_fd2(n + '0', i);
	else if (n >= 10)
	{
		ft_putunsi_fd(n / 10, i);
		ft_putchar_fd2(n % 10 + '0', i);
	}
}
