/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/18 18:51:32 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.outer_wall);
	mlx_destroy_image(env->mlx, env->img.inner_wall);
	mlx_destroy_image(env->mlx, env->img.floor);
	mlx_destroy_image(env->mlx, env->img.door);
	mlx_destroy_image(env->mlx, env->img.coin);
	mlx_destroy_image(env->mlx, env->img.player_r);
	mlx_destroy_window(env->mlx, env->win);
}

void	open_images(t_env *env, int *width, int *height, char **map)
{
	env->win = mlx_new_window(env->mlx, get_map_width(map) * 32,
			get_map_height(map) * 32, "so_long");
	env->img.outer_wall = mlx_xpm_file_to_image(env->mlx, "assetes/floor33.xpm",
			width, height);
	env->img.opened_door = mlx_xpm_file_to_image(env->mlx,
			"assetes/opened_door.xpm", width, height);
	env->img.inner_wall = mlx_xpm_file_to_image(env->mlx, "assetes/wall_gb.xpm",
			width, height);
	env->img.floor = mlx_xpm_file_to_image(env->mlx, "assetes/floorT.xpm",
			width, height);
	env->img.door = mlx_xpm_file_to_image(env->mlx, "assetes/idle.xpm", width,
			height);
	env->img.coin = mlx_xpm_file_to_image(env->mlx, "assetes/coin.xpm", width,
			height);
	env->img.player_r = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/right032.xpm", width, height);
	env->img.player_d = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/down1_32.xpm", width, height);
	env->img.player_u = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/up1_32.xpm", width, height);
	env->img.player_l = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/left032.xpm", width, height);
}

void	set_up_map(char **map)
{
	t_env	env;
	t_var	var;
	int		width;
	int		height;
	t_point	p_pos;

	var.map = map;
	p_pos = item_postion(map, 'P');
	var.p_pos = &p_pos;
	env.mlx = mlx_init();
	open_images(&env, &width, &height, map);
	var.env = &env;
	if (!render_map(map, &env, env.img.player_r, &p_pos))
	{
		destroy_images(&env);
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
