/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:36 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/19 17:26:09 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handel_down_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1'
		&& ((var->map[var->p_pos->y + 1][var->p_pos->x] == 'E'
				&& check_collect(var->map))
			|| (var->map[var->p_pos->y][var->p_pos->x] == 'E')))
	{
		var->p_pos->y = var->p_pos->y + 1;
		var->p_pos->x = var->p_pos->x;
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	else if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1')
	{
		var->p_pos->y = var->p_pos->y + 1;
		var->p_pos->x = var->p_pos->x;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	render_map(var->map, var->env, var->env->img.player_d, var->p_pos);
}

void	handle_right_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x + 1] == 'E'
				&& check_collect(var->map))
			|| (var->map[var->p_pos->y][var->p_pos->x] == 'E')))
	{
		var->p_pos->y = var->p_pos->y;
		var->p_pos->x = var->p_pos->x + 1;
		(*move)++;
		ft_printf("%d moves\n", *move);
	}
	else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1')
	{
		var->p_pos->y = var->p_pos->y;
		var->p_pos->x = var->p_pos->x + 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	render_map(var->map, var->env, var->env->img.player_r, var->p_pos);
}

void	handle_up_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y - 1][var->p_pos->x] != '1'
		&& ((var->map[var->p_pos->y - 1][var->p_pos->x] == 'E'
				&& check_collect(var->map))
			|| (var->map[var->p_pos->y][var->p_pos->x] == 'E')))
	{
		var->p_pos->y = var->p_pos->y - 1;
		var->p_pos->x = var->p_pos->x;
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	else if (var->map[var->p_pos->y - 1][var->p_pos->x] != '1')
	{
		var->p_pos->y = var->p_pos->y - 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	render_map(var->map, var->env, var->env->img.player_u, var->p_pos);
}

void	handle_left_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x - 1] == 'E'
				&& check_collect(var->map))
			|| var->map[var->p_pos->y][var->p_pos->x] == 'E'))
	{
		var->p_pos->y = var->p_pos->y;
		var->p_pos->x = var->p_pos->x - 1;
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1')
	{
		var->p_pos->x = var->p_pos->x - 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	render_map(var->map, var->env, var->env->img.player_l, var->p_pos);
}

int	movment_handler(int keycode, t_var *var)
{
	static int	move;

	if (keycode == 1 || keycode == 125)
		handel_down_move(var, &move);
	if (keycode == 2 || keycode == 124)
		handle_right_move(var, &move);
	if (keycode == 13 || keycode == 126)
		handle_up_move(var, &move);
	if (keycode == 0 || keycode == 123)
		handle_left_move(var, &move);
	return (1);
}
