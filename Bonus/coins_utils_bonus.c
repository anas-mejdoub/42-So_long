/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:58:51 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 12:09:53 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_coins	*last_coin(t_coins *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	check_c(t_coins_var *variable)
{
	if (variable->var->map[variable->coins->c_pos.y][variable->coins->c_pos.x]
		== 'C')
		return (1);
	return (0);
}

int	open_coins(t_env *env, int *width, int *height)
{
	env->img.coin = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin1.xpm",
			width, height);
	env->img.coin2 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin2.xpm",
			width, height);
	env->img.coin3 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin3.xpm",
			width, height);
	env->img.coin4 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin4.xpm",
			width, height);
	env->img.coin5 = mlx_xpm_file_to_image(env->mlx, "assetes/coins/coin5.xpm",
			width, height);
	env->img.floor_counter = mlx_xpm_file_to_image(env->mlx,
			"assetes/floor_counter.xpm", width, height);
	env->img.upper_counter = mlx_xpm_file_to_image(env->mlx,
			"assetes/upper_counter.xpm", width, height);
	if (!check_coins_assetes(env))
	{
		ft_printf("coins\n");
		return (0);
	}
	return (1);
}

int	check_coins_assetes(t_env *env)
{
	if (!env->img.coin || !env->img.coin2 || !env->img.coin3 || !env->img.coin4
		|| !env->img.coin5 || !env->img.floor_counter
		|| !env->img.upper_counter)
		return (0);
	return (1);
}

void	img_value(t_coins_var variable)
{
	while (variable.coins)
	{
		variable.coins->img = variable.var->env->img.coin;
		variable.coins = variable.coins->next;
	}
}
