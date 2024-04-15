/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/15 22:46:02 by amejdoub         ###   ########.fr       */
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
            else if (map[i][y] == '0' || map[i][y] == 'P')
            {
                void *img = mlx_xpm_file_to_image(mlx, "assetes/floor33.xpm", &width, &height);
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            else if (map[i][y] == 'E')
            {
                img = mlx_xpm_file_to_image(mlx, "assetes/idle.xpm", &width, &height);
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
    // void	*mlx;
	// void	*img;
	// char	*relative_path = "assetes/floor33.xpm";
	// int		img_width;
	// int		img_height;
	// int		img_width2;
	// int		img_height2;
	// int		img_width3;
	// int		img_height3;
	// int		img_width4;
	// int		img_height4;
	// mlx = mlx_init();
    // void *window = mlx_new_window(mlx, get_map_width(map) * 32, get_map_height(map) * 32, "test");
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// void *img_wall = mlx_xpm_file_to_image(mlx, "assetes/wall_v.xpm", &img_width2, &img_height2);
	// void *img_door = mlx_xpm_file_to_image(mlx, "assetes/idle.xpm", &img_width3, &img_height3);
	// void *player = mlx_xpm_file_to_image(mlx, "assetes/player.xpm", &img_width4, &img_height4);
    // int i = 0;
    // int y = 0;
    // int z = 0;
    // int h = 0;
    // while (map[i])
    // {
    //     y = 0;
    //     z = 0;
    //     while (map[i][y])
    //     {
    //         if (map[i][y] == '1')
    //         {
    //             mlx_put_image_to_window(mlx, window, img_wall, z, h);
    //         }
    //         else if (map[i][y] == '0' || map[i][y] == 'P')
    //         {
    //             mlx_put_image_to_window(mlx, window, img, z, h);
    //         }
    //         else if (map[i][y] == 'E')
    //         {
    //             mlx_put_image_to_window(mlx, window, img_door, z, h);
    //         }
    //         if (map[i][y] == 'P')
    //         {
    //             mlx_put_image_to_window(mlx, window, player, z, h);

    //         }
    //         z += 32;
    //         y++;
    //     }
    //     h += 32;
    //     i++;
    // }
    // mlx_loop(mlx);
}
