/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extens_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:11:39 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/26 11:38:45 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!ft_strncmp(extension, ".ber", 5))
		return (1);
	write(2, "invalid extension !\n", 21);
	exit(1);
}

void	printf_err(void)
{
	write(2, "invalid map !\n", 15);
	exit(1);
}
