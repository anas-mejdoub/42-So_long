/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:36 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/27 16:32:25 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handel_down_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y + 1][var->p_pos->x] == 'X')
		var->game_state++;
	if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		var->p_pos->y = var->p_pos->y + 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_d, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
	else if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1'
		&& var->map[var->p_pos->y + 1][var->p_pos->x] == 'E'
		&& !check_collect(var->map))
	{
		var->game_state++;
		var->win = WIN;
		ft_printf("congrats You win !\ngame closing\n");
	}
	else if (var->map[var->p_pos->y + 1][var->p_pos->x] != '1')
	{
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
		var->p_pos->y = var->p_pos->y + 1;
		if (var->map[var->p_pos->y][var->p_pos->x] != 'E')
		{
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
			var->map[var->p_pos->y][var->p_pos->x] = '0';
		}
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_d, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
	else
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		if (var->map[var->p_pos->y][var->p_pos->x] == 'E')
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_d, var->p_pos->x * 32, var->p_pos->y * 32);
	}
}

// right move !!!!!!!!!!!
void	handle_right_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y][var->p_pos->x + 1] == 'X')
		var->game_state++;
	if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		var->p_pos->x = var->p_pos->x + 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.sprint_right, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_r, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
	else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1'
		&& var->map[var->p_pos->y][var->p_pos->x + 1] == 'E'
		&& !check_collect(var->map))
	{
		var->game_state++;
		var->win = WIN;
		ft_printf("congrats You won !\ngame closing\n");
		// destroy_images(var->env, 1);
		// free2d(var->map);
		// exit(0);
	}
	else if (var->map[var->p_pos->y][var->p_pos->x + 1] != '1')
	{
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
		var->p_pos->x = var->p_pos->x + 1;
		if (var->map[var->p_pos->y][var->p_pos->x] != 'E')
		{
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
			var->map[var->p_pos->y][var->p_pos->x] = '0';
		}
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.sprint_right, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
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

void	handle_up_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y - 1][var->p_pos->x] == 'X')
		var->game_state++;
	if (var->map[var->p_pos->y - 1][var->p_pos->x] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		var->p_pos->y = var->p_pos->y - 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_u, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
	else if (var->map[var->p_pos->y - 1][var->p_pos->x] != '1'
		&& var->map[var->p_pos->y - 1][var->p_pos->x] == 'E'
		&& !check_collect(var->map))
	{
		var->game_state++;
		var->win = WIN;
		ft_printf("congrats You won !\ngame closing\n");
		// destroy_images(var->env, 1);
		// free2d(var->map);
		// exit(0);
	}
	else if (var->map[var->p_pos->y - 1][var->p_pos->x] != '1')
	{
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
		var->p_pos->y = var->p_pos->y - 1;
		if (var->map[var->p_pos->y][var->p_pos->x] != 'E')
		{
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
			var->map[var->p_pos->y][var->p_pos->x] = '0';
		}
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_u, var->p_pos->x * 32, (var->p_pos->y) * 32);
		(*move)++;
	}
	else
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		if (var->map[var->p_pos->y][var->p_pos->x] == 'E')
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_u, var->p_pos->x * 32, var->p_pos->y * 32);
	}
}

void	handle_left_move(t_var *var, int *move)
{
	if (var->map[var->p_pos->y][var->p_pos->x - 1] == 'X')
		var->game_state++;
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1'
		&& ((var->map[var->p_pos->y][var->p_pos->x] == 'E'
				&& check_collect(var->map))))
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.door, var->p_pos->x * 32, var->p_pos->y * 32);
		var->p_pos->x = var->p_pos->x - 1;
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, var->p_pos->y * 32);
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.player_l, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1'
		&& var->map[var->p_pos->y][var->p_pos->x - 1] == 'E'
		&& !check_collect(var->map))
	{
		var->game_state++;
		var->win = WIN;
		ft_printf("congrats You won !\ngame closing\n");
	}
	else if (var->map[var->p_pos->y][var->p_pos->x - 1] != '1')
	{
		var->map[var->p_pos->y][var->p_pos->x] = '0';
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
		var->p_pos->x = var->p_pos->x - 1;
		if (var->map[var->p_pos->y][var->p_pos->x] != 'E')
		{
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.floor, var->p_pos->x * 32, (var->p_pos->y) * 32);
			var->map[var->p_pos->y][var->p_pos->x] = '0';
		}
		mlx_put_image_to_window(var->env->mlx, var->env->win,
			var->env->img.sprint_left, var->p_pos->x * 32, var->p_pos->y * 32);
		(*move)++;
	}
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

void	change_door(t_var *var)
{
	t_point	pos;
	static int  n;

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

int	movment_handler(int keycode, t_var *var)
{
	static int	move;
	char		*str_move;
	char		*str;
	
	if (var->game_state == GAME_END)
	{
		if (keycode == 36)
		{
			destroy_images(var->env, check_winner(var->map));
			exit (0);
		}
		return 0;
	}
	if (keycode == 1 || keycode == 125)
		handel_down_move(var, &move);
	else if (keycode == 2 || keycode == 124)
		handle_right_move(var, &move);
	else if (keycode == 13 || keycode == 126)
		handle_up_move(var, &move);
	else if (keycode == 0 || keycode == 123)
		handle_left_move(var, &move);
	else if (keycode == 53)
	{
		var->game_state++;
		var->win = LOSE;
	}
		if (!check_collect(var->map))
		change_door(var);
	str_move = ft_itoa(move);
	str = ft_strjoin("moves : ", str_move);
	build_counter_z(var);
	mlx_string_put(var->env->mlx, var->env->win, 0, get_map_height(var->map)
		* 32, 0xf58d42, str);
	free(str_move);
	free(str);
	return (1);
}


/*

	enum {
		GAME_START = 0,
		GAME_IN = 1,
		GAME_END = 2,
	}

	int game_state = 0;
	game_loop_hook
	{
		if (game_state == GAME_START)
			render_game_menu();
		else if (game_stat == GAME_IN)
			render_game_stuff();
			if (enemy touches me) 
				game_state++;
		else {
			mlx_clear_window();
			render_game_over();
		}
	}
	
	key_handler 
	{
		if (game_state == GAME_START)
			if (key_pressed == "Enter")
				game_state++;
		else if (game_state == GAME_IN)
			if (i touch enemy)
				game_state++;
		else {
			if (key_pressed == "Enter")
				destroy_everything();
		}
	}
	
	render_game_over() {
		mlx_put_image_to_window(&img, SCREEN_H, SCREEN_W);
	}

*/