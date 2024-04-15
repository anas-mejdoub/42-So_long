/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/15 17:08:21 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"
// #include "../Libft/libft.h"

int main(void)
{
    // if (argc == 1)
    //     return 0;
    // char **map = map_parsing(argv[1]);
    // // free(map);
    // if (!map)
    // {
    //     write (2, "Error map !", 12);
    //     exit (0);
    // }
    // int i = 0;
    // // while (map[i])
    // // {
    // //     ft_printf("%s\n", map[i]);
    // //     i++;
    // // }
    // void *mlx;
    // mlx = mlx_init();
    // void *img = mlx_new_image(mlx, 1920, 1080);
    // // mlx_new_image(mlx1, 100, 100);
    // // mlx
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
    // free2d(map);
    // free2d(img);
    // int i = 0;
    // while (map[i])
    // {
    //     ft_printf("%s\n", map[i]);
    //     i++;
    // }
    
    // system("leaks so_long");

    void	*mlx;
	void	*img;
	char	*relative_path = "skull_v1_1.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
    void *window = mlx_new_window(mlx, 1000, 1000, "test");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, window, img, 500, 500);
    mlx_loop(mlx);
}