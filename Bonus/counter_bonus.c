/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:52:19 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/21 17:22:36 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	intialcounter(t_var *var)
{
	int	marge;

	build_counter_z(var);
	marge = (get_map_height(var->map) * 1.3 * 32) - (1.3 * 32);
	mlx_string_put(var->env->mlx, var->env->win, 0, marge, 0xf58d42,
		"moves : 0");
}

void	build_counter_z(t_var *var)
{
	int	more_height;
	int	y;
	int	height;
	int	i;
	int	width;

	more_height = get_map_height(var->map) * 1.3 * 32;
	y = 0;
	height = get_map_height(var->map) * 32;
	i = 0;
	width = get_map_width(var->map) * 32;
	while (y < more_height)
	{
		i = 0;
		while (i < width)
		{
			mlx_put_image_to_window(var->env->mlx, var->env->win,
				var->env->img.outer_wall, i, height + y);
			i += 32;
		}
		y += 32;
	}
}
