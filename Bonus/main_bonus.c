/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:51:07 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/24 12:39:03 by amejdoub         ###   ########.fr       */
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
			(get_map_height(map) + 1) * 32, "so_long");
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
	if (!check_assets(env))
		return (0);
	return (1);
}

int	check_coins_assetes(t_env *env)
{
	if (!env->img.coin || !env->img.coin2 || !env->img.coin3 || !env->img.coin4
		|| !env->img.coin5 || !env->img.floor_counter
		|| !env->img.upper_counter)
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
	env->img.floor_counter = mlx_xpm_file_to_image(env->mlx,
			"assetes/floor_counter.xpm", width, height);
	env->img.upper_counter = mlx_xpm_file_to_image(env->mlx,
			"assetes/upper_counter.xpm", width, height);
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

void	*ask_for_img(t_coins_var *variable)
{
	void		*res;
	static int	n;

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
int	check_c(t_coins_var *variable)
{
	if (variable->var->map[variable->coins->c_pos.y][variable->coins->c_pos.x] == 'C')
		return (1);
	return (0);
}

void	enemy_caller(t_coins_var *variable)
{
	static int	timer;

	timer++;
	if (timer == 7000)
		handle_enemy(variable);
	else if (timer > 7000)
		timer = 0;
}
int	render_coins(t_coins_var *variable)
{
	static int	timer;
	t_coins		*tmp;
	void		*img;

	timer++;
	tmp = variable->coins;
	enemy_caller(variable);
	if (timer == 1000)
	{
		img = ask_for_img(variable);
		while (variable->coins)
		{
			if (check_c(variable))
			{
				mlx_put_image_to_window(variable->var->env->mlx,
					variable->var->env->win, variable->var->env->img.floor,
					variable->coins->c_pos.x * 32, variable->coins->c_pos.y
					* 32);
				mlx_put_image_to_window(variable->var->env->mlx,
					variable->var->env->win, img, variable->coins->c_pos.x
					* 32, variable->coins->c_pos.y * 32);
			}
			variable->coins = variable->coins->next;
		}
	}
	else if (timer > 1000)
		timer = 0;
	variable->coins = tmp;
	return (1);
}

void	handle_enemy(t_coins_var *variable)
{
	t_point		pos;
	t_enemies	*tmp;
	
	tmp = variable->enemies;
	while (variable->enemies)
	{
		pos = search_p(variable->var->map, variable->enemies->e_pos,
				*variable->var->p_pos);
		if (pos.x != variable->enemies->e_pos.x || pos.y != variable->enemies->e_pos.y)
		{
			mlx_put_image_to_window(variable->var->env->mlx,
				variable->var->env->win, variable->enemies->img,
				pos.x * 32, pos.y * 32);
			mlx_put_image_to_window(variable->var->env->mlx,
				variable->var->env->win, variable->var->env->img.floor,
				variable->enemies->e_pos.x * 32, variable->enemies->e_pos.y * 32);
			variable->var->map[variable->enemies->e_pos.y][variable->enemies->e_pos.x] = '0';
			variable->var->map[pos.y][pos.x] = 'X';
			variable->enemies->e_pos = pos;
			
		}
		if (pos.x == variable->var->p_pos->x && pos.y == variable->var->p_pos->y)
			closing_game(variable->var);
		variable->enemies = variable->enemies->next;
	}
	variable->enemies = tmp;
}

void	img_value(t_coins_var variable)
{
	while (variable.coins)
	{
		variable.coins->img = variable.var->env->img.coin;
		variable.coins = variable.coins->next;
	}
}

int	check_enemy_assets(t_env *env)
{
	if (!env->img.enemy_up || !env->img.enemy_down || !env->img.enemy_left
		|| !env->img.enemy_right)
		return (0);
	return (1);
}

int	open_enemy(t_env *env, int *width, int *height)
{
	env->img.enemy_up = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/enemy_up.xpm", width, height);
	env->img.enemy_down = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/enemy_down.xpm", width, height);
	env->img.enemy_right = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/enemy_right.xpm", width, height);
	env->img.enemy_left = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/enemy_left.xpm", width, height);
	if (!check_enemy_assets(env))
		return (0);
	return (1);
}
t_enemies	*last_enemy(t_enemies *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
void	add_enemies_back(t_enemies **lst, t_point pos)
{
	t_enemies	*new;

	if (!lst)
	{
		return ;
	}
	new = (t_enemies *)malloc(sizeof(t_enemies));
	if (!new)
		return ;
	new->e_pos.x = pos.x;
	new->e_pos.y = pos.y;
	new->next = NULL;
	if (!(*lst))
	{
		*lst = new;
	}
	else
		last_enemy(*lst)->next = new;
}

void	fill_enemies(t_coins_var *variable)
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
			if (variable->var->map[i][j] == 'X')
			{
				add_enemies_back(&(variable)->enemies, (t_point){i, j});
			}
			j++;
		}
		i++;
	}
}

void	enemies_img_intial(t_coins_var variable)
{
	while (variable.enemies)
	{
		variable.enemies->img = variable.var->env->img.enemy_right;
		variable.enemies = variable.enemies->next;
	}
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
	variable.enemies = NULL;
	intialcounter(&var);
	fill_coins(&variable);
	fill_enemies(&variable);
	img_value(variable);
	enemies_img_intial(variable);
	render_map(map, &env, env.img.player_r, &p_pos);
	mlx_loop_hook(env.mlx, render_coins, &variable);
	mlx_hook(env.win, 3, 0, movment_handler, &var);
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
