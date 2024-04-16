/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/16 16:57:35 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

t_point player_postion(char **map)
{
    t_point pos; 
    pos.y  = 0;
    pos.x  = 0;
    while (map[pos.y])
    {
        pos.x = 0;
        while (map[pos.y][pos.x])
        {
            if (map[pos.y][pos.x] == 'P')
                return (pos);
            pos.x++;
        }
        pos.y++;
    }
    return (pos);
}
int key_handler(int keycode)
{
    if (keycode == 53)
        ft_printf("ESCAPE");
    else if (keycode == 0 || keycode == 123)
        ft_printf("LEFT (A / ARROW_LEFT)");
    else if (keycode == 2 || keycode == 124)
        ft_printf("RIGHT (D / ARROW_RIGHT)");
    else if (keycode == 1 || keycode == 125)
        ft_printf("DOWN (S / ARROW_DOWN)");
    else if (keycode == 13 || keycode == 126)
        ft_printf("lfoq");
    else
        ft_printf("%d\n", keycode);
    return (0);
}
int  movment_handler(int keycode, t_var *var)
{
    t_point pos = player_postion(var->map);
    ft_printf ("%c\n", var->map[pos.y + 1][pos.x]);
    if (keycode == 1)
    {
        ft_printf("down\n");
        if (var->map[pos.y + 1][pos.x] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y + 1][pos.x] = 'P';
            render_map(var->map, var->env);
            return 1;
        }
    }
    if (keycode == 2)
    {
        ft_printf("right\n");
        if (var->map[pos.y][pos.x + 1] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y][pos.x + 1] = 'P';
            render_map(var->map, var->env);
            return 1;
        }
    }
    if (keycode == 13)
    {
        ft_printf("up\n");
        if (var->map[pos.y - 1][pos.x] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y - 1][pos.x] = 'P';
            render_map(var->map, var->env);
            return 1;
        }
    }
    if (keycode == 0)
    {
        ft_printf("left\n");
         ft_printf("up\n");
        if (var->map[pos.y][pos.x - 1] != '1')
        {
            var->map[pos.y][pos.x] = '0';
            var->map[pos.y][pos.x - 1] = 'P';
            render_map(var->map, var->env);
            return 1;
        }
    }
    return 1;
}
void render_map(char **map, t_env *env)
{
    int i = 0;
    int width;
    int height;
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
                if (i == 0 || y == 0 || y == get_map_width(map) - 1 || i == get_map_height(map) - 1)
                    env->img = mlx_xpm_file_to_image(env->mlx, "assetes/floor33.xpm", &width, &height);
                else
                    env->img = mlx_xpm_file_to_image(env->mlx, "assetes/wall_gb.xpm", &width, &height);
                mlx_put_image_to_window(env->mlx, env->win, env->img, z, h);
            }
            else if (map[i][y] == '0' || map[i][y] == 'P' || map[i][y] == 'C' || map[i][y] == 'E')
            {
                env->img = mlx_xpm_file_to_image(env->mlx, "assetes/floorT.xpm", &width, &height);
                mlx_put_image_to_window(env->mlx, env->win, env->img, z, h);
            }
            if (map[i][y] == 'E')
            {
                env->img = mlx_xpm_file_to_image(env->mlx, "assetes/idle.xpm", &width, &height);
                mlx_put_image_to_window(env->mlx, env->win, env->img, z, h);
            }
            if (map[i][y] == 'C')
            {
                env->img = mlx_xpm_file_to_image(env->mlx, "assetes/coin.xpm", &width, &height);
                mlx_put_image_to_window(env->mlx, env->win, env->img, z, h);
            }
            if (map[i][y] == 'P')
            {
                env->img = mlx_xpm_file_to_image(env->mlx, "assetes/right0.xpm", &width, &height);
                mlx_put_image_to_window(env->mlx, env->win, env->img, z, h);
            }
            z += 32;
            y++;
        }
        h += 32;
        i++;
    }
}
void set_up_map(char **map)
{
    t_env env;
    t_var var;
    var.map = map;
    // env->map = map;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, get_map_width(map) * 32, get_map_height(map) * 32, "so_long");
    var.env = &env;
    render_map(map, &env);
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
}
