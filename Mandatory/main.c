/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/15 22:52:29 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"
void set_up_map(char **map)
{
    int width;
    int height;
    void	*mlx;
	void	*img;
    int i = 0;
    
    mlx = mlx_init();
    void *window = mlx_new_window(mlx, get_map_width(map) * 32, get_map_height(map) * 32, "so_long");
    int y = 0;
    int z = 0;
    int h = 0;
    while (map[i])
    {
        y = 0;
        z = 0;
        while (map[i][y])
        {
            if (map[i][y] == '1')
            {
                void *img = mlx_xpm_file_to_image(mlx, "assetes/wall_v.xpm", &width, &height);
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            else if (map[i][y] == '0' || map[i][y] == 'P' || map[i][y] == 'C')
            {
                void *img = mlx_xpm_file_to_image(mlx, "assetes/floor33.xpm", &width, &height);
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            else if (map[i][y] == 'E')
            {
                img = mlx_xpm_file_to_image(mlx, "assetes/idle.xpm", &width, &height);
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            if (map[i][y] == 'C')
            {
                img = mlx_xpm_file_to_image(mlx, "assetes/coin.xpm", &width, &height);
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            if (map[i][y] == 'P')
            {
                img = mlx_xpm_file_to_image(mlx, "assetes/player.xpm", &width, &height);
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            z += 32;
            y++;
        }
        h += 32;
        i++;
    }
    mlx_loop(mlx);
}
int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;
    char **map = map_parsing(argv[1]);
    if (!map)
    {
        write (2, "Error map !", 12);
        exit (0);
    }
    set_up_map(map);
}
