/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:41:14 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/18 18:52:06 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	item_postion(char **map, char c)
{
	t_point	pos;

	pos.y = 0;
	pos.x = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return ((t_point){-1, -1});
}

int	check_winner(char **map)
{
	t_point	pos_exit;
	t_point	pos_coins;

	pos_exit = item_postion(map, 'E');
	pos_coins = item_postion(map, 'C');
	if (pos_exit.y == -1 && pos_exit.x == -1 && pos_coins.y == -1
		&& pos_coins.x == -1)
		return (1);
	else if (pos_coins.y == -1 && pos_coins.x == -1)
		return (2);
	return (0);
}
