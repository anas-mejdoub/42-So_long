/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 15:38:46 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"
// #include "../Libft/libft.h"

int main()
{
    char **map = map_parsing();
    // free(map);
    if (!map)
    {
        write (2, "Error map !", 12);
        exit (0);
    }
    int i = 0;
    while (map[i])
    {
        ft_printf("%s\n", map[i]);
        i++;
    }
    
    // system("leaks a.out");
}