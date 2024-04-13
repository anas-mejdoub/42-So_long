/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:34:56 by amejdoub          #+#    #+#             */
/*   Updated: 2024/02/21 19:15:55 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd2(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_putstr_fd2(char *s, int *i)
{
	if (!s)
	{
		ft_putstr_fd2("(null)", i);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd2(*s, i);
		s++;
	}
}
