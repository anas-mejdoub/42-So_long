/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:52:19 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/19 19:15:20 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	intialcounter(t_var *var)
{
	int	marge;

	marge = (get_map_height(var->map) * 1.3 * 32) - (1.3 * 32);
	mlx_string_put(var->env->mlx, var->env->win, 0, marge, 0x0f1232f, "moves : 0");
}
