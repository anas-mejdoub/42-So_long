/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/16 18:39:20 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"


t_point item_postion(char **map, char c)
{
    t_point pos; 
    pos.y  = 0;
    pos.x  = 0;
    while (map[pos.y])
    {
        pos.x = 0;
        while (map[pos.y][pos.x])
        {
            if (map[pos.y][pos.x] == c)
                return (pos);
            pos.x++;
        }
        pos.y++;
    }
    return ((t_point){-1, -1});
}
int check_winner(char **map)
{
    t_point pos = item_postion(map, 'E');
    if (pos.y == -1 && pos.x == -1)
        return (1);
    return (0);
    
}
int  movment_handler(int keycode, t_var *var)
{
    t_point pos = item_postion(var->map, 'P');
    if (keycode == 1)
    {
        if (var->map[pos.y + 1][pos.x] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y + 1][pos.x] = 'P';
            render_map(var->map, var->env);
        }
    }
    if (keycode == 2)
    {
        if (var->map[pos.y][pos.x + 1] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y][pos.x + 1] = 'P';
            render_map(var->map, var->env);
        }
    }
    if (keycode == 13)
    {
        if (var->map[pos.y - 1][pos.x] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y - 1][pos.x] = 'P';
            render_map(var->map, var->env);
        }
    }
    if (keycode == 0)
    {
        if (var->map[pos.y][pos.x - 1] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y][pos.x - 1] = 'P';
            render_map(var->map, var->env);
        }
    }
    return 1;
}

int render_map(char **map, t_env *env)
{
    int i = 0;
    int y = 0;
    int z = 0;
    int h = 0;
    if (check_winner(map))
    {
        ft_printf("congrats You win !\ngame closing\n");
        exit(0);
        return (0);
    }
    while (map[i])
    {
        y = 0;
        z = 0;
        while (map[i][y])
        {
            if (map[i][y] == '1')
            {
                if (i == 0 || y == 0 || y == get_map_width(map) - 1 || i == get_map_height(map) - 1)
                    mlx_put_image_to_window(env->mlx, env->win, env->img.outer_wall, z, h);
                else
                    mlx_put_image_to_window(env->mlx, env->win, env->img.inner_wall, z, h);
            }
            if (map[i][y] == '0' || map[i][y] == 'P' || map[i][y] == 'C' || map[i][y] == 'E')
                mlx_put_image_to_window(env->mlx, env->win, env->img.floor, z, h);
            if (map[i][y] == 'E')
                mlx_put_image_to_window(env->mlx, env->win, env->img.door, z, h);
            if (map[i][y] == 'C')
                mlx_put_image_to_window(env->mlx, env->win, env->img.coin, z, h);
            if (map[i][y] == 'P')
                mlx_put_image_to_window(env->mlx, env->win, env->img.player_r, z, h);
            z += 32;
            y++;
        }
        h += 32;
        i++;
    }
    return (1);
}
void set_up_map(char **map)
{
    t_env env;
    t_var var;
    int width;
    int height;
    var.map = map;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, get_map_width(map) * 32, get_map_height(map) * 32, "so_long");
    var.env = &env;
    env.img.outer_wall = mlx_xpm_file_to_image(env.mlx, "assetes/floor33.xpm", &width, &height);
    env.img.inner_wall = mlx_xpm_file_to_image(env.mlx, "assetes/wall_gb.xpm", &width, &height);
    env.img.floor = mlx_xpm_file_to_image(env.mlx, "assetes/floorT.xpm", &width, &height);
    env.img.door = mlx_xpm_file_to_image(env.mlx, "assetes/idle.xpm", &width, &height);
    env.img.coin = mlx_xpm_file_to_image(env.mlx, "assetes/coin.xpm", &width, &height);
    env.img.player_r = mlx_xpm_file_to_image(env.mlx, "assetes/right0.xpm", &width, &height);
    // int res = render_map(map, &env);
    if (!render_map(map, &env))
    {
        ft_printf("ttt\n");
        mlx_destroy_image(env.mlx, env.img.outer_wall);
        mlx_destroy_image(env.mlx, env.img.inner_wall);
        mlx_destroy_image(env.mlx, env.img.floor);
        mlx_destroy_image(env.mlx, env.img.door);
        mlx_destroy_image(env.mlx, env.img.coin);
        mlx_destroy_image(env.mlx, env.img.player_r);
        mlx_destroy_window(env.mlx, env.win);
        exit(0);
    }
    mlx_hook(env.win, 2, 1L << 0, movment_handler, &var);
    mlx_loop(env.mlx);
}
int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;
    char **map = map_parsing(argv[1]);
    if (!map)
    {
        write (2, "Error map !\n", 13);
        exit (0);
    }
    // t_point pos = player_postion(map);
    // ft_printf("%c\n", map[pos.y][pos.x -1 ]);
    set_up_map(map);
    return 0;
}
