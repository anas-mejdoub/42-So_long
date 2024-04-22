/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/22 19:06:04 by amejdoub         ###   ########.fr       */
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

int	check_coins_assetes(t_env *env)
{
	if (!env->img.coin || !env->img.coin2 || !env->img.coin3 || !env->img.coin4
		 || !env->img.coin5 || !env->img.floor_counter || !env->img.upper_counter)
		return (0);
	return (1);
}

int	open_coins(t_env *env, int *width, int *height)
{
	env->img.coin = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin1.xpm",
			width, height);
	env->img.coin2 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin2.xpm",
			width, height);
	env->img.coin3 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin3.xpm",
			width, height);
	env->img.coin4 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin4.xpm",
			width, height);
	env->img.coin5 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin5.xpm",
			width, height);
	env->img.floor_counter = mlx_xpm_file_to_image(env->mlx, "assetes/floor_counter.xpm",
			width, height);
	env->img.upper_counter = mlx_xpm_file_to_image(env->mlx, "assetes/upper_counter.xpm",
			width, height);
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

t_coins	*last_coin(t_coins *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	add_coins_back(t_coins **lst, t_point pos)
{
	t_coins	*new;

	if (!lst)
	{
		return ;
	}
	new = (t_coins *)malloc(sizeof(t_coins));
	if (!new)
		return ;
	new->c_pos = pos;
	new->next = NULL;
	if (!(*lst))
	{
		*lst = new;
	}
	else
		last_coin(*lst)->next = new;
}

void	fill_coins(t_coins_var *variable)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (variable->var->map[i])
	{
		j = 0;
		while (variable->var->map[i][j])
		{
			if (variable->var->map[i][j] == 'C')
			{
				add_coins_back(&(variable)->coins, (t_point){i, j});
			}
			j++;
		}
		i++;
	}
}

void *ask_for_img(t_coins_var *variable)
{
	void *res;
	static int n;
	if (n == 0)
		res = variable->var->env->img.coin;
	else if (n == 1)
		res = variable->var->env->img.coin2;
	else if (n == 2)
		res = variable->var->env->img.coin3;
	else if (n == 3)
		res = variable->var->env->img.coin4;
	else if (n == 4)
		res = variable->var->env->img.coin5;
	else
	{
		n = 0;
		res = variable->var->env->img.coin;
	}
	n++;
	return (res);
}
int check_c(t_coins_var *variable)
{
	if (variable->var->map[variable->coins->c_pos.y][variable->coins->c_pos.x] == 'C')
		return 1;
	return 0;
}

void render_enemy(t_coins_var *variable)
{
	int i = 0;
	int j;

	while (variable->var->map[i])
	{
		j = 0;
		while (variable->var->map[i][j])
		{
			if (variable->var->map[i][j] == 'X')
			{
				mlx_put_image_to_window(variable->var->env->mlx, variable->var->env->win, variable->var->env->img.enemy_right, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}
void enemy_caller(t_coins_var *variable)
{
	static int timer;
	timer++;
	if (timer == 2000)
		handle_enemy(variable);
	else if (timer > 9000)
		timer = 0;
}
int	render_coins(t_coins_var *variable)
{
	static int timer;
	timer++;
	t_coins *tmp = variable->coins;
	enemy_caller(variable);
	if (timer == 500)
	{
	void *test = ask_for_img(variable);
	while (variable->coins)
	{
		if (check_c(variable))
		{
			mlx_put_image_to_window(variable->var->env->mlx,
			variable->var->env->win, variable->var->env->img.floor, variable->coins->c_pos.x * 32,
			variable->coins->c_pos.y * 32);
			mlx_put_image_to_window(variable->var->env->mlx,
			variable->var->env->win, test, variable->coins->c_pos.x * 32,
			variable->coins->c_pos.y * 32);
		}
		variable->coins = variable->coins->next;
	}
	}
	else if (timer > 500)
		timer = 0;
	variable->coins = tmp;
	return (1);
}

void handle_enemy(t_coins_var *variable)
{
	t_point pos;
	int i = 0;
	int j;
	pos.x = 0;
	pos.y = 0;

	while (variable->var->map[i])
	{
		j = 0;
		while (variable->var->map[i][j])
		{
			if (variable->var->map[i][j] == 'X' && pos.x != j && pos.y != i)
			{
				pos = search_p(variable->var->map, (t_point){i, j}, *variable->var->p_pos);
				ft_printf ("the pos : %d %d\n", pos.y, pos.x);
				mlx_put_image_to_window(variable->var->env->mlx, variable->var->env->win, variable->var->env->img.enemy_right, pos.x * 32, pos.y * 32);
				mlx_put_image_to_window(variable->var->env->mlx, variable->var->env->win, variable->var->env->img.floor, j * 32, i * 32);
				variable->var->map[i][j] = '0';
				variable->var->map[pos.y][pos.x] = 'X';
			}
			j++;
		}
		i++;
	}
}

void img_value(t_coins_var variable)
{
	while (variable.coins)
	{
		variable.coins->img = variable.var->env->img.coin;
		variable.coins = variable.coins->next;
	}
}

int check_enemy_assets(t_env *env)
{
	if (!env->img.enemy_up || !env->img.enemy_down || !env->img.enemy_left || !env->img.enemy_right)
		return (0);
	return (1);
}

int  open_enemy(t_env *env, int *width, int *height)
{
	env->img.enemy_up = mlx_xpm_file_to_image(env->mlx, "assetes/enemy/enemy_up.xpm",
			width, height);
	env->img.enemy_down = mlx_xpm_file_to_image(env->mlx, "assetes/enemy/enemy_down.xpm",
			width, height);
	env->img.enemy_right = mlx_xpm_file_to_image(env->mlx, "assetes/enemy/enemy_right.xpm",
			width, height);
	env->img.enemy_left = mlx_xpm_file_to_image(env->mlx, "assetes/enemy/enemy_left.xpm",
			width, height);
	if (!check_enemy_assets(env))
		return (0);
	return (1);
}

int	set_up_map(char **map)
{
	t_env		env;
	t_var		var;
	int			width;
	int			height;
	t_point		p_pos;
	t_coins_var	variable;

	var.map = map;
	p_pos = item_postion(map, 'P');
	var.p_pos = &p_pos;
	env.mlx = mlx_init();
	if (!open_images(&env, &width, &height, map) || !open_coins(&env, &width,
			&height) || !open_enemy(&env, &width, &height))
	{
		free2d(map);
		ft_putstr_fd("problem with the assetes !\n", 2);
		exit(1);
	}
	var.env = &env;
	variable.var = &var;
	variable.coins = NULL;
	intialcounter(&var);
	fill_coins(&variable);
	img_value(variable);
	render_map(map, &env, env.img.player_r, &p_pos);
	mlx_loop_hook(env.mlx, render_coins, &variable);
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
