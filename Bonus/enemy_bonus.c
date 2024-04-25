/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/25 17:46:28 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	search_p(t_coins_var *variable, t_point enemy)
{
	if (variable->var->p_pos->y > enemy.y && variable->var->map[enemy.y
		+ 1][enemy.x] != '1' && variable->var->map[enemy.y + 1][enemy.x] != 'C'
		&& variable->var->map[enemy.y + 1][enemy.x] != 'E'
		&& variable->var->map[enemy.y + 1][enemy.x] != 'X')
	{
		variable->enemies->img = variable->var->env->img.enemy_down;
		return ((t_point){enemy.y + 1, enemy.x});
	}
	else if (variable->var->p_pos->y < enemy.y && variable->var->map[enemy.y
		- 1][enemy.x] != '1' && variable->var->map[enemy.y - 1][enemy.x] != 'C'
		&& variable->var->map[enemy.y - 1][enemy.x] != 'E'
		&& variable->var->map[enemy.y - 1][enemy.x] != 'X')
	{
		variable->enemies->img = variable->var->env->img.enemy_up;
		return ((t_point){enemy.y - 1, enemy.x});
	}
	else if (variable->var->p_pos->x > enemy.x
		&& variable->var->map[enemy.y][enemy.x + 1] != '1'
		&& variable->var->map[enemy.y][enemy.x + 1] != 'C'
		&& variable->var->map[enemy.y][enemy.x + 1] != 'E'
		&& variable->var->map[enemy.y][enemy.x + 1] != 'X')
	{
		variable->enemies->img = variable->var->env->img.enemy_right;
		return ((t_point){enemy.y, enemy.x + 1});
	}
	else if (variable->var->p_pos->x < enemy.x
		&& variable->var->map[enemy.y][enemy.x - 1] != '1'
		&& variable->var->map[enemy.y][enemy.x - 1] != 'C'
		&& variable->var->map[enemy.y][enemy.x - 1] != 'E'
		&& variable->var->map[enemy.y][enemy.x - 1] != 'X')
	{
		variable->enemies->img = variable->var->env->img.enemy_left;
		return ((t_point){enemy.y, enemy.x - 1});
	}
	return (enemy);
}
