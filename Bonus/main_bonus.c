/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/30 14:44:30 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	red_cross(t_var *var)
{
	destroy_images(var->env, check_winner(var->map));
	free2d(var->map);
	if (var->win == LOSE)
		ft_printf("you lost\ngame closing\n");
	exit(0);
}

int	set_up_map(char **map)
{
	t_env		env;
	t_var		var;
	t_point		p_pos;
	t_coins_var	variable;

	var.map = map;
	p_pos = item_postion(map, 'P');
	var.p_pos = &p_pos;
	env.mlx = mlx_init();
	var.env = &env;
	var.win = LOSE;
	var.game_state = GAME_START;
	open_window_images(&var);
	variable.var = &var;
	variable.coins = NULL;
	variable.enemies = NULL;
	mlx_hook(env.win, 3, 0, movment_handler, &var);
	fill_coins(&variable);
	fill_enemies(&variable);
	img_value(variable);
	enemies_img_intial(variable);
	mlx_loop_hook(env.mlx, render_coins, &variable);
	mlx_hook(env.win, 17, 0, red_cross, &var);
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
	return (0);
}
