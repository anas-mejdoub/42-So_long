/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:02:17 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 12:50:05 by amejdoub         ###   ########.fr       */
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

int	open_images(t_env *env, int *width, int *height)
{
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
			"assetes/player/naruto_right.xpm", width, height);
	env->img.player_d = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_downrr.xpm", width, height);
	env->img.player_u = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_upr.xpm", width, height);
	env->img.player_l = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_left.xpm", width, height);
	env->img.sprint_right = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_sprint_right.xpm", width, height);
	env->img.sprint_left = mlx_xpm_file_to_image(env->mlx,
			"assetes/player/naruto_sprint_left.xpm", width, height);
	if (!check_assets(env))
		return (0);
	return (1);
}

int	open_window_images(t_var *var)
{
	int	height;
	int	width;

	var->env->win = mlx_new_window(var->env->mlx, get_map_width(var->map) * 32,
			(get_map_height(var->map) + 1) * 32, "so_long");
	if (!open_images(var->env, &width, &height) || !open_coins(var->env, &width,
			&height) || !open_enemy(var->env, &width, &height))
	{
		free2d(var->map);
		ft_putstr_fd("problem with the assetes !\n", 2);
		exit(1);
	}
	return (1);
}
