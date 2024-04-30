/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/30 12:17:03 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_env *env, int n)
{
	mlx_destroy_image(env->mlx, env->img.outer_wall);
	mlx_destroy_image(env->mlx, env->img.inner_wall);
	mlx_destroy_image(env->mlx, env->img.floor);
	mlx_destroy_image(env->mlx, env->img.opened_door);
	mlx_destroy_image(env->mlx, env->img.coin);
	mlx_destroy_image(env->mlx, env->img.player_r);
	mlx_destroy_image(env->mlx, env->img.player_u);
	mlx_destroy_image(env->mlx, env->img.player_d);
	mlx_destroy_image(env->mlx, env->img.player_l);
	mlx_destroy_window(env->mlx, env->win);
	if (n == 0)
		mlx_destroy_image(env->mlx, env->img.door);
}

int	open_images(t_env *env, int *width, int *height, char **map)
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
	env->img.coin = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin1.xpm",
			width, height);
	env->img.player_r = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_right.xpm", width, height);
	env->img.player_d = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_downrr.xpm", width, height);
	env->img.player_u = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_upr.xpm", width, height);
	env->img.player_l = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_left.xpm", width, height);
	if (!check_assets(env))
		return (0);
	return (1);
}

int	closing_game(t_var *var)
{
	destroy_images(var->env, check_winner(var->map));
	ft_printf("You lost ! hehe\n");
	free2d(var->map);
	exit(0);
}

int	set_up_map(char **map)
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
	if (!open_images(&env, &width, &height, map))
	{
		free2d(map);
		ft_putstr_fd("problem with the assetes !\n", 2);
		exit(1);
	}
	var.env = &env;
	render_map(map, &env, env.img.player_r, &p_pos);
	mlx_hook(env.win, 2, 0, movment_handler, &var);
	mlx_hook(env.win, 17, 0, closing_game, &var);
	mlx_loop(env.mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc == 1)
		return (0);
	map = map_parsing(argv[1]);
	if (!map)
	{
		write(2, "Error map !\n", 13);
		exit(0);
	}
	set_up_map(map);
	free2d(map);
	return (0);
}
