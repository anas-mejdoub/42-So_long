/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/19 22:34:58 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			get_map_height(map) * 1.3 * 32, "so_long");
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
	env->img.player_r = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/right032.xpm", width, height);
	env->img.player_d = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/down1_32.xpm", width, height);
	env->img.player_u = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/up1_32.xpm", width, height);
	env->img.player_l = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/left032.xpm", width, height);
	if (!check_assets(env))
		return (0);
	return (1);
}

int check_coins_assetes(t_env *env)
{
	if (!env->img.coin|| !env->img.coin2 || !env->img.coin3
		|| !env->img.coin4 || !env->img.coin5)
		return (0);
	return (1);
}

int open_coins(t_env *env , int *width, int *height)
{
	env->img.coin = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin1.xpm", width,
			height);
	env->img.coin2 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin2.xpm", width,
			height);
	env->img.coin3 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin3.xpm", width,
			height);
	env->img.coin4 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin4.xpm", width,
			height);
	env->img.coin5 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin5.xpm", width,
			height);
	if (!check_coins_assetes(env))
	{	
		return (0);
	}
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
	if (!open_images(&env, &width, &height, map) || !open_coins(&env, &width, &height))
	{
		free2d(map);
		ft_putstr_fd("problem with the assetes !\n", 2);
		exit(1);
	}
	var.env = &env;
	intialcounter(&var);
	render_map(map, &env, env.img.player_r, &p_pos);
	// mlx_loop_hook(env.mlx, )
	mlx_hook(env.win, 2, 0, movment_handler, &var);
	mlx_hook(env.win, 17, 0, closing_game, &var);
	mlx_loop(env.mlx);
	return (0);
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
	free2d(map);
	return (0);
}
