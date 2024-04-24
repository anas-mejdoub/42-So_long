/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/24 18:27:10 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	search_p(t_coins_var *variable, t_point enemy)
{
	if (variable->var->p_pos->y > enemy.y)
	{
		if (variable->var->map[enemy.y + 1][enemy.x] != '1' && variable->var->map[enemy.y + 1][enemy.x] != 'C'
			&& variable->var->map[enemy.y + 1][enemy.x] != 'E' && variable->var->map[enemy.y
			+ 1][enemy.x] != 'X')
			{
			enemy.y++;
			variable->enemies->img = variable->var->env->img.enemy_down;
			}
	}
	else if (variable->var->p_pos->y < enemy.y)
	{
		if (variable->var->map[enemy.y - 1][enemy.x] != '1' && variable->var->map[enemy.y - 1][enemy.x] != 'C'
			&& variable->var->map[enemy.y - 1][enemy.x] != 'E' && variable->var->map[enemy.y
			- 1][enemy.x] != 'X')
			{
			enemy.y--;
			variable->enemies->img = variable->var->env->img.enemy_up;
				
			}
	}
	else if (variable->var->p_pos->x > enemy.x)
	{
		if (variable->var->map[enemy.y][enemy.x + 1] != '1' && variable->var->map[enemy.y][enemy.x + 1] != 'C'
			&& variable->var->map[enemy.y][enemy.x + 1] != 'E' && variable->var->map[enemy.y][enemy.x
			+ 1] != 'X')
			{
			enemy.x++;
			variable->enemies->img = variable->var->env->img.enemy_right;
			}
	}
	else if (variable->var->p_pos->x < enemy.x)
	{
		if (variable->var->map[enemy.y][enemy.x - 1] != '1' && variable->var->map[enemy.y][enemy.x - 1] != 'C'
			&& variable->var->map[enemy.y][enemy.x - 1] != 'E' && variable->var->map[enemy.y][enemy.x
			- 1] != 'X')
			{
			enemy.x--;
			variable->enemies->img = variable->var->env->img.enemy_left;

			}
	}
	return (enemy);
}
