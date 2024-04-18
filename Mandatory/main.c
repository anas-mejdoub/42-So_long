/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/18 11:58:16 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

t_point	item_postion(char **map, char c)
{
	t_point	pos;

	pos.y = 0;
	pos.x = 0;
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

int	check_winner(char **map)
{
	t_point	pos_exit;
	t_point	pos_coins;

	pos_exit = item_postion(map, 'E');
	pos_coins = item_postion(map, 'C');
	if (pos_exit.y == -1 && pos_exit.x == -1 && pos_coins.y == -1
		&& pos_coins.x == -1)
		return (1);
	else if (pos_coins.y == -1 && pos_coins.x == -1)
        return (2);
	return (0);
}
// void handle_px(char **map)
// {

// }
int	movment_handler(int keycode, t_var *var)
{
	// t_point	pos;

	// pos = *var->p_pos;
	if (keycode == 1)
	{
		if ((var->map[var->p_pos->y + 1][var->p_pos->x] == 'E' && check_collect(var->map)) || var->map[var->p_pos->y][var->p_pos->x] == 'E')
		{
			ft_printf("YES\n");
			var->p_pos->y = var->p_pos->y + 1;
			var->p_pos->x = var->p_pos->x;
		}
		else if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1')
		{
			var->p_pos->y = var->p_pos->y + 1;
			var->p_pos->x = var->p_pos->x;
			var->map[var->p_pos->y][var->p_pos->x] = '0';
		}
		render_map(var->map, var->env, var->env->img.player_d, var->p_pos);
	}
	if (keycode == 2)
	{
		if ((var->map[var->p_pos->y][var->p_pos->x + 1] == 'E' && check_collect(var->map)) || var->map[var->p_pos->y][var->p_pos->x] == 'E')
		{
			ft_printf("YES\n");
			var->p_pos->y = var->p_pos->y;
			var->p_pos->x = var->p_pos->x + 1;
		}
		else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1')
		{
			var->p_pos->y = var->p_pos->y;
			var->p_pos->x = var->p_pos->x + 1;
			var->map[var->p_pos->y][var->p_pos->x] = '0';
		}
		render_map(var->map, var->env, var->env->img.player_r, var->p_pos);
	}
	if (keycode == 13)
	{
		if ((var->map[var->p_pos->y - 1][var->p_pos->x] == 'E' && check_collect(var->map)) || var->map[var->p_pos->y][var->p_pos->x] == 'E')
		{
			ft_printf("YES\n");
			var->p_pos->y = var->p_pos->y - 1;
			var->p_pos->x = var->p_pos->x;
			
		}
		else if (var->map[var->p_pos->y - 1][var->p_pos->x] != '1')
		{
			var->map[var->p_pos->y][var->p_pos->x] = '0';
			var->p_pos->y = var->p_pos->y - 1;
		}
		render_map(var->map, var->env, var->env->img.player_u, var->p_pos);
	}
	if (keycode == 0)
	{
		if ((var->map[var->p_pos->y][var->p_pos->x - 1] == 'E' && check_collect(var->map)) || var->map[var->p_pos->y][var->p_pos->x] == 'E')
		{
			ft_printf("YES\n");
			var->p_pos->y = var->p_pos->y;
			var->p_pos->x = var->p_pos->x - 1;
		}
		else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1')
		{
			var->map[var->p_pos->y][var->p_pos->x] = '0';
			var->p_pos->y = var->p_pos->y;
			var->p_pos->x = var->p_pos->x - 1;
		}
		render_map(var->map, var->env, var->env->img.player_l, var->p_pos);
	}
	return (1);
}

int	render_map(char **map, t_env *env, void *player_dir, t_point *p_pos)
{
	int	i;
	int	y;
	int	z;
	int	h;

	i = 0;
	y = 0;
	z = 0;
	h = 0;
    
	if (check_winner(map) == 1)
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
				if (i == 0 || y == 0 || y == get_map_width(map) - 1
					|| i == get_map_height(map) - 1)
					mlx_put_image_to_window(env->mlx, env->win,
						env->img.outer_wall, z, h);
				else
					mlx_put_image_to_window(env->mlx, env->win,
						env->img.inner_wall, z, h);
			}
			if (map[i][y] == '0' || map[i][y] == 'P' || map[i][y] == 'C'
				|| map[i][y] == 'E')
				mlx_put_image_to_window(env->mlx, env->win, env->img.floor, z,
					h);
			if (map[i][y] == 'E')
                {
                    if (check_winner(map) == 2)
                        env->img.door = env->img.opened_door;
					mlx_put_image_to_window(env->mlx, env->win, env->img.door, z,
					h);
                }
			if (map[i][y] == 'C' && (i != p_pos->y || p_pos->x != y))
				mlx_put_image_to_window(env->mlx, env->win, env->img.coin, z,
					h);
			z += 32;
			y++;
		}
		h += 32;
		i++;
	}
		if (map[p_pos->y][p_pos->x] == 'C')
			map[p_pos->y][p_pos->x] = '0';
		mlx_put_image_to_window(env->mlx, env->win, player_dir, p_pos->x * 32, p_pos->y *32);
	return (1);
}

void	set_up_map(char **map)
{
	t_env	env;
	t_var	var;
	int		width;
	int		height;
	t_point p_pos;

	var.map = map;
	p_pos = item_postion(map, 'P');
	var.p_pos = &p_pos;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, get_map_width(map) * 32,
			get_map_height(map) * 32, "so_long");
	var.env = &env;
	env.img.outer_wall = mlx_xpm_file_to_image(env.mlx, "assetes/floor33.xpm",
			&width, &height);
	env.img.opened_door = mlx_xpm_file_to_image(env.mlx,
			"assetes/opened_door.xpm", &width, &height);
	env.img.inner_wall = mlx_xpm_file_to_image(env.mlx, "assetes/wall_gb.xpm",
			&width, &height);
	env.img.floor = mlx_xpm_file_to_image(env.mlx, "assetes/floorT.xpm", &width,
			&height);
	env.img.door = mlx_xpm_file_to_image(env.mlx, "assetes/idle.xpm", &width,
			&height);
	env.img.coin = mlx_xpm_file_to_image(env.mlx, "assetes/coin.xpm", &width,
			&height);
	env.img.player_r = mlx_xpm_file_to_image(env.mlx, "assetes/player/right032.xpm",
			&width, &height);
	env.img.player_d = mlx_xpm_file_to_image(env.mlx,
			"assetes/player/down1_32.xpm", &width, &height);
	env.img.player_u = mlx_xpm_file_to_image(env.mlx, "assetes/player/up1_32.xpm",
			&width, &height);
	env.img.player_l = mlx_xpm_file_to_image(env.mlx,
			"assetes/player/left032.xpm", &width, &height);
	if (!render_map(map, &env, env.img.player_r, &p_pos))
	{
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
void	check_leaks(void)
{
	system("leaks so_long");
}
int	main(int argc, char *argv[])
{
	char	**map;

	atexit(check_leaks);
	if (argc == 1)
		return (0);
	map = map_parsing(argv[1]);
	if (!map)
	{
		write(2, "Error map !\n", 13);
		exit(0);
	}
	set_up_map(map);
	return (0);
}
