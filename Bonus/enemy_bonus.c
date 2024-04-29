/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 12:10:16 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	search_p(t_coins_var *variable, t_point enemy)
{
	if (variable->var->p_pos->y > enemy.y && !ft_strchr("1CX",
			variable->var->map[enemy.y + 1][enemy.x]))
	{
		variable->enemies->img = variable->var->env->img.enemy_down;
		return ((t_point){enemy.y + 1, enemy.x});
	}
	else if (variable->var->p_pos->y < enemy.y && !ft_strchr("1CX",
			variable->var->map[enemy.y - 1][enemy.x]))
	{
		variable->enemies->img = variable->var->env->img.enemy_up;
		return ((t_point){enemy.y - 1, enemy.x});
	}
	else if (variable->var->p_pos->x > enemy.x && !ft_strchr("1CX",
			variable->var->map[enemy.y][enemy.x + 1]))
	{
		variable->enemies->img = variable->var->env->img.enemy_right;
		return ((t_point){enemy.y, enemy.x + 1});
	}
	else if (variable->var->p_pos->x < enemy.x && !ft_strchr("1CX",
			variable->var->map[enemy.y][enemy.x - 1]))
	{
		variable->enemies->img = variable->var->env->img.enemy_left;
		return ((t_point){enemy.y, enemy.x - 1});
	}
	return (enemy);
}

void	handle_enemy(t_coins_var *variable)
{
	t_point		pos;
	t_enemies	*tmp;

	tmp = variable->enemies;
	while (variable->enemies)
	{
		pos = search_p(variable, variable->enemies->e_pos);
		if (pos.x != variable->enemies->e_pos.x
			|| pos.y != variable->enemies->e_pos.y)
			handle_enemy_handler(variable, pos);
		variable->enemies->e_pos.x = pos.x;
		variable->enemies->e_pos.y = pos.y;
		if (pos.x == variable->var->p_pos->x
			&& pos.y == variable->var->p_pos->y)
		{
			variable->var->game_state++;
			variable->var->win = LOSE;
		}
		variable->enemies = variable->enemies->next;
	}
	variable->enemies = tmp;
}

void	handle_enemy_handler(t_coins_var *variable, t_point pos)
{
	mlx_put_image_to_window(variable->var->env->mlx, variable->var->env->win,
		variable->var->env->img.floor, variable->enemies->e_pos.x * 32,
		variable->enemies->e_pos.y * 32);
	if (variable->var->map[variable->enemies->e_pos.y]
		[variable->enemies->e_pos.x]
		== 'E')
	{
		mlx_put_image_to_window(variable->var->env->mlx,
			variable->var->env->win, variable->var->env->img.door,
			variable->enemies->e_pos.x * 32, variable->enemies->e_pos.y * 32);
	}
	if (variable->var->map[variable->enemies->e_pos.y][variable->enemies->e_pos.x] != 'E')
		variable->var->map[variable->enemies->e_pos.y][variable->enemies->e_pos.x] = '0';
	variable->enemies->e_pos.x = pos.x;
	variable->enemies->e_pos.y = pos.y;
	mlx_put_image_to_window(variable->var->env->mlx, variable->var->env->win,
		variable->enemies->img, variable->enemies->e_pos.x * 32,
		variable->enemies->e_pos.y * 32);
	if (variable->var->map[variable->enemies->e_pos.y][variable->enemies->e_pos.x] != 'E')
		variable->var->map[variable->enemies->e_pos.y][variable->enemies->e_pos.x] = 'X';
	variable->enemies->e_pos = pos;
}

int	open_enemy(t_env *env, int *width, int *height)
{
	env->img.enemy_up = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/itachi_up.xpm", width, height);
	env->img.enemy_down = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/itachi_down.xpm", width, height);
	env->img.enemy_right = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/itachi_right.xpm", width, height);
	env->img.enemy_left = mlx_xpm_file_to_image(env->mlx,
			"assetes/enemy/itachi_left32.xpm", width, height);
	if (!check_enemy_assets(env))
		return (0);
	return (1);
}

int	check_enemy_assets(t_env *env)
{
	if (!env->img.enemy_up || !env->img.enemy_down || !env->img.enemy_left
		|| !env->img.enemy_right)
		return (0);
	return (1);
}
