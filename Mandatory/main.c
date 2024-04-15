/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/15 22:18:36 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

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
    ft_printf("%d\n", get_map_height(map));
    void	*mlx;
	void	*img;
	char	*relative_path = "assetes/floor33.xpm";
	int		img_width;
	int		img_height;
	int		img_width2;
	int		img_height2;
	int		img_width3;
	int		img_height3;
	mlx = mlx_init();
    void *window = mlx_new_window(mlx, get_map_width(map) * 32, get_map_height(map) * 32, "test");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	void *img_wall = mlx_xpm_file_to_image(mlx, "assetes/wall_volc.xpm", &img_width2, &img_height2);
	void *img_door = mlx_xpm_file_to_image(mlx, "assetes/idle.xpm", &img_width3, &img_height3);
    int i = 0;
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
                mlx_put_image_to_window(mlx, window, img_wall, z, h);
            }
            else if (map[i][y] == '0')
            {
                mlx_put_image_to_window(mlx, window, img, z, h);
            }
            else if (map[i][y] == 'E')
            {
                mlx_put_image_to_window(mlx, window, img_door, z, h);
            }
            z += 32;
            y++;
        }
        h += 32;
        i++;
    }
    mlx_loop(mlx);
}
