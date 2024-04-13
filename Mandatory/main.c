/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 21:48:24 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"
// #include "../Libft/libft.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;
    char **map = map_parsing(argv[1]);
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
    void *mlx1;
    mlx1 = mlx_init();
    mlx_new_window(mlx1, 900, 900, "first one");
    // mlx_new_image(mlx1, 100, 100);
    // mlx
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