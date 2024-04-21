/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:36 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/21 19:41:49 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handel_down_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1'
		&& ((var->map[var->p_pos->y + 1][var->p_pos->x] == 'E'
				&& check_collect(var->map))
			|| (var->map[var->p_pos->y][var->p_pos->x] == 'E')))
	{
		var->p_pos->y = var->p_pos->y + 1;
		(*move)++;
		ft_printf("%d move\n", *move);
	}
	else if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1')
	{
		var->p_pos->y = var->p_pos->y + 1;
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
		var->p_pos->x = var->p_pos->x + 1;
		(*move)++;
		ft_printf("%d moves\n", *move);
	}
	else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1')
	{
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
	int			marge;
	char		*str_move;
	char		*str;

	marge = (get_map_height(var->map) * 1.3 * 32) - (1.3 * 32);
	if (keycode == 1 || keycode == 125)
		handel_down_move(var, &move);
	else if (keycode == 2 || keycode == 124)
		handle_right_move(var, &move);
	else if (keycode == 13 || keycode == 126)
		handle_up_move(var, &move);
	else if (keycode == 0 || keycode == 123)
		handle_left_move(var, &move);
	else if (keycode == 53)
		closing_game(var);
	str_move = ft_itoa(move);
	str = ft_strjoin("moves : ", str_move);
	build_counter_z(var);
	mlx_string_put(var->env->mlx, var->env->win, 0, marge, 0xf58d42, str);
	free(str_move);
	free(str);
	return (1);
}
