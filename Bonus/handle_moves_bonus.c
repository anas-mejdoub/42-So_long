/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:36 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 16:24:08 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_right_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y][var->p_pos->x + 1] == 'X')
		var->game_state++;
	if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
		handle_door(var, move, (t_point){var->p_pos->y, var->p_pos->x + 1},
			var->env->img.sprint_right);
	else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1'
		&& var->map[var->p_pos->y][var->p_pos->x + 1] == 'E'
		&& !check_collect(var->map))
		handle_win(var);
	else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1')
		handle_free_move(var, move, (t_point){var->p_pos->y, var->p_pos->x + 1},
			var->env->img.sprint_right);
	else
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		if (var->map[var->p_pos->y][var->p_pos->x] == 'E')
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_r, var->p_pos->x * 32, var->p_pos->y * 32);
	}
}

void	handle_left_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y][var->p_pos->x - 1] == 'X')
		var->game_state++;
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
		handle_door(var, move, (t_point){var->p_pos->y, var->p_pos->x - 1},
			var->env->img.sprint_left);
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1'
		&& var->map[var->p_pos->y][var->p_pos->x - 1] == 'E'
		&& !check_collect(var->map))
		handle_win(var);
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1')
		handle_free_move(var, move, (t_point){var->p_pos->y, var->p_pos->x - 1},
			var->env->img.sprint_left);
	else
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		if (var->map[var->p_pos->y][var->p_pos->x] == 'E')
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_l, var->p_pos->x * 32, var->p_pos->y * 32);
	}
}

void	movment_handler_helper(int keycode, t_var *var, int *move)
{
	if (keycode == 1 || keycode == 125)
		up_down_move(var, move, (t_point){var->p_pos->y + 1, var->p_pos->x},
			var->env->img.player_d);
	else if (keycode == 2 || keycode == 124)
		handle_right_move(var, move);
	else if (keycode == 13 || keycode == 126)
		up_down_move(var, move, (t_point){var->p_pos->y - 1, var->p_pos->x},
			var->env->img.player_u);
	else if (keycode == 0 || keycode == 123)
		handle_left_move(var, move);
	else if (keycode == 53)
		red_cross(var);
	if (!check_collect(var->map))
		change_door(var);
}

void	str_handler(t_var *var, char *move)
{
	char	*str;

	str = ft_strjoin("moves : ", move);
	build_counter_z(var);
	mlx_string_put(var->env->mlx, var->env->win, 0, get_map_height(var->map)
		* 32, 0xf58d42, str);
	free(move);
	free(str);
}

int	movment_handler(int keycode, t_var *var)
{
	static int	move;

	if (var->game_state == GAME_END)
	{
		if (keycode == 14)
		{
			destroy_images(var->env, check_winner(var->map));
			exit(0);
		}
		return (0);
	}
	if (var->game_state == GAME_START)
	{
		if (keycode == 36)
		{
			mlx_clear_window(var->env->mlx, var->env->win);
			var->game_state++;
		}
		return (0);
	}
	movment_handler_helper(keycode, var, &move);
	str_handler(var, ft_itoa(move));
	return (1);
}
