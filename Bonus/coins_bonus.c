/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:52:37 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 11:55:45 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_coins(t_coins_var *variable)
{
	static int	timer;
	t_coins		*tmp;
	static int	render_caller;

	if (variable->var->game_state == GAME_START)
		game_start(variable->var);
	if (variable->var->game_state == GAME_IN)
	{
		timer++;
		render_caller++;
		if (render_caller == 1)
			render_map(variable);
		tmp = variable->coins;
		enemy_caller(variable);
		if (timer == 1000)
			render_coins_helper(variable);
		else if (timer > 1000)
			timer = 0;
		variable->coins = tmp;
	}
	else if (variable->var->game_state == GAME_END)
		closing_game(variable->var);
	return (1);
}

void	render_coins_helper(t_coins_var *variable)
{
	void	*img;

	img = ask_for_img(variable);
	while (variable->coins)
	{
		if (check_c(variable))
		{
			mlx_put_image_to_window(variable->var->env->mlx,
				variable->var->env->win, variable->var->env->img.floor,
				variable->coins->c_pos.x * 32, variable->coins->c_pos.y * 32);
			mlx_put_image_to_window(variable->var->env->mlx,
				variable->var->env->win, img, variable->coins->c_pos.x * 32 + 7,
				variable->coins->c_pos.y * 32 + 7);
		}
		variable->coins = variable->coins->next;
	}
}

void	fill_coins(t_coins_var *variable)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (variable->var->map[i])
	{
		j = 0;
		while (variable->var->map[i][j])
		{
			if (variable->var->map[i][j] == 'C')
			{
				add_coins_back(&(variable)->coins, (t_point){i, j});
			}
			j++;
		}
		i++;
	}
}

void	add_coins_back(t_coins **lst, t_point pos)
{
	t_coins	*new;

	if (!lst)
	{
		return ;
	}
	new = (t_coins *)malloc(sizeof(t_coins));
	if (!new)
		return ;
	new->c_pos = pos;
	new->next = NULL;
	if (!(*lst))
	{
		*lst = new;
	}
	else
		last_coin(*lst)->next = new;
}

void	*ask_for_img(t_coins_var *variable)
{
	void		*res;
	static int	n;

	if (n == 0)
		res = variable->var->env->img.coin;
	else if (n == 1)
		res = variable->var->env->img.coin2;
	else if (n == 2)
		res = variable->var->env->img.coin3;
	else if (n == 3)
		res = variable->var->env->img.coin4;
	else if (n == 4)
		res = variable->var->env->img.coin5;
	else
	{
		n = 0;
		res = variable->var->env->img.coin;
	}
	n++;
	return (res);
}
