/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:31 by amejdoub          #+#    #+#             */
/*   Updated: 2023/12/16 11:07:57 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow_checker(unsigned long nbr, int new_nb, int sign)
{
	if (sign == 1)
	{
		if ((nbr >= 922337203685477580 && new_nb > 7)
			|| (nbr >= 922337203685477581))
			return (-1);
	}
	if (sign == -1)
	{
		if ((nbr >= 922337203685477580 && new_nb > 8)
			|| (nbr >= 922337203685477581))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	int				overflow;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		overflow = overflow_checker(res, *str - '0', sign);
		if (overflow != 1)
			return (overflow);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
