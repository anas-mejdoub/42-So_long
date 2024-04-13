/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 21:32:49 by amejdoub         ###   ########.fr       */
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
    // void *ptr;
    void *mlx1;
    mlx1 = mlx_init();
    mlx_new_window(mlx1, 900, 900, "first one");
    mlx_loop(mlx1);
    free2d(map);
    // int i = 0;
    // while (map[i])
    // {
    //     ft_printf("%s\n", map[i]);
    //     i++;
    // }
    
    // system("leaks so_long");
}