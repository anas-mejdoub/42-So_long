/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:48:50 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 12:10:03 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemies	*last_enemy(t_enemies *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	add_enemies_back(t_enemies **lst, t_point pos)
{
	t_enemies	*new;

	if (!lst)
	{
		return ;
	}
	new = (t_enemies *)malloc(sizeof(t_enemies));
	if (!new)
		return ;
	new->e_pos.x = pos.x;
	new->e_pos.y = pos.y;
	new->next = NULL;
	if (!(*lst))
	{
		*lst = new;
	}
	else
		last_enemy(*lst)->next = new;
}

void	fill_enemies(t_coins_var *variable)
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
			if (variable->var->map[i][j] == 'X')
			{
				add_enemies_back(&(variable)->enemies, (t_point){i, j});
			}
			j++;
		}
		i++;
	}
}

void	enemies_img_intial(t_coins_var variable)
{
	while (variable.enemies)
	{
		variable.enemies->img = variable.var->env->img.enemy_down;
		variable.enemies = variable.enemies->next;
	}
}

void	enemy_caller(t_coins_var *variable)
{
	static int	timer;

	timer++;
	if (timer == 7000)
		handle_enemy(variable);
	else if (timer > 7000)
		timer = 0;
}
