/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:34:39 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 16:06:45 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_door(t_var *var, int *move, t_point new, void *pimg)
{
	mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.floor,
		var->p_pos->x * 32, var->p_pos->y * 32);
	mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.door,
		var->p_pos->x * 32, var->p_pos->y * 32);
	var->p_pos->y = new.y;
	var->p_pos->x = new.x;
	var->map[var->p_pos->y][var->p_pos->x] = '0';
	mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.floor,
		var->p_pos->x * 32, var->p_pos->y * 32);
	mlx_put_image_to_window(var->env->mlx, var->env->win, pimg, var->p_pos->x
		* 32, var->p_pos->y * 32);
	(*move)++;
}

void	handle_win(t_var *var)
{
	var->game_state++;
	var->win = WIN;
	ft_printf("congrats You win !\ngame closing\n");
}

void	handle_free_move(t_var *var, int *move, t_point new, void *pimg)
{
	var->map[var->p_pos->y][var->p_pos->x] = '0';
	mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.floor,
		var->p_pos->x * 32, (var->p_pos->y) * 32);
	var->p_pos->y = new.y;
	var->p_pos->x = new.x;
	if (var->map[var->p_pos->y][var->p_pos->x] != 'E')
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		var->map[var->p_pos->y][var->p_pos->x] = '0';
	}
	mlx_put_image_to_window(var->env->mlx, var->env->win, pimg, var->p_pos->x
		* 32, var->p_pos->y * 32);
	(*move)++;
}

void	up_down_move(t_var *var, int *move, t_point new, void *pimg)
{
	if (var->map[new.y][new.x] == 'X')
		var->game_state++;
	if (var->map[new.y][new.x] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
		handle_door(var, move, new, pimg);
	else if (var->map[new.y][new.x] != '1' && var->map[new.y][new.x] == 'E'
		&& !check_collect(var->map))
		handle_win(var);
	else if (var->map[new.y][new.x] != '1')
		handle_free_move(var, move, new, pimg);
	else
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		if (var->map[var->p_pos->y][var->p_pos->x] == 'E')
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win, pimg,
			var->p_pos->x * 32, var->p_pos->y * 32);
	}
}

void	change_door(t_var *var)
{
	t_point		pos;
	static int	n;

	var->env->img.door = var->env->img.opened_door;
	if (n == 0)
	{
		pos = item_postion(var->map, 'E');
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.opened_door, pos.x * 32, pos.y * 32);
		n++;
	}
	if (check_winner(var->map) == 1)
	{
		ft_printf("congrats You win !\ngame closing\n");
		destroy_images(var->env, 1);
		free2d(var->map);
		exit(0);
	}
}
