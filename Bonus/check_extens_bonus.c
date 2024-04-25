/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extens_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:11:39 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/25 12:26:03 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int check_extension(char *filename)
{
    char *extension = ft_strrchr(filename, '.');
    if (!ft_strncmp(extension, ".ber", 5))
        return (1);
    return (0);
}

void printf_err()
{
    write(2, "invalid map !\n", 15);
	exit(1);
}