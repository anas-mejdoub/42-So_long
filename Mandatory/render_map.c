/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:37:53 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/19 17:50:42 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(char **map, t_env *env, void *player_dir, t_point *p_pos)
{
	if (check_winner(map) == 1)
	{
		ft_printf("congrats You win !\ngame closing\n");
		destroy_images(env, 1);
		free2d(map);
		exit(0);
	}
	render_helper((t_var){map, env, p_pos}, 0, 0, (t_point){0, 0});
	if (map[p_pos->y][p_pos->x] == 'C')
		map[p_pos->y][p_pos->x] = '0';
	mlx_put_image_to_window(env->mlx, env->win, player_dir, p_pos->x * 32,
		p_pos->y * 32);
	return (1);
}

void	render_helper(t_var var, int i, int y, t_point point)
{
	while (var.map[i])
	{
		point.x = 0;
		y = 0;
		while (var.map[i][y])
		{
			if (var.map[i][y] == '1')
				build_outer_wall(var.map, (t_point){i, y}, (t_point){point.y,
					point.x}, var.env);
			if (var.map[i][y] == '0' || var.map[i][y] == 'P'
				|| var.map[i][y] == 'C' || var.map[i][y] == 'E')
				mlx_put_image_to_window(var.env->mlx, var.env->win,
					var.env->img.floor, point.x, point.y);
			if (var.map[i][y] == 'E')
				render_exit(&var, &point);
			if (var.map[i][y] == 'C' && (i != var.p_pos->y
					|| var.p_pos->x != y))
				mlx_put_image_to_window(var.env->mlx, var.env->win,
					var.env->img.coin, point.x, point.y);
			point.x += 32;
			y++;
		}
		point.y += 32;
		i++;
	}
}

void	render_exit(t_var *var, t_point *point)
{
	if (check_winner(var->map) == 2)
		mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.opened_door,
			point->x, point->y);
	else
		mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.door,
			point->x, point->y);
}

void	build_outer_wall(char **map, t_point p, t_point p2, t_env *env)
{
	if (p.y == 0 || p.x == 0 || p.x == get_map_width(map) - 1
		|| p.y == get_map_height(map) - 1)
		mlx_put_image_to_window(env->mlx, env->win, env->img.outer_wall, p2.x,
			p2.y);
	else
		mlx_put_image_to_window(env->mlx, env->win, env->img.inner_wall, p2.x,
			p2.y);
}

int	check_assets(t_env *env)
{
	if (!env->img.outer_wall || !env->img.opened_door || !env->img.inner_wall
		|| !env->img.floor || !env->img.door || !env->img.coin
		|| !env->img.player_r || !env->img.player_d || !env->img.player_u
		|| !env->img.player_l)
		return (0);
	return (1);
}
