/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/24 11:38:14 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	search_p(char **map, t_point enemy, t_point player)
{
	if (player.y > enemy.y)
	{
		if (map[enemy.y + 1][enemy.x] != '1' && map[enemy.y + 1][enemy.x] != 'C'
			&& map[enemy.y + 1][enemy.x] != 'E' && map[enemy.y
			+ 1][enemy.x] != 'X')
			enemy.y++;
	}
	else if (player.y < enemy.y)
	{
		if (map[enemy.y - 1][enemy.x] != '1' && map[enemy.y - 1][enemy.x] != 'C'
			&& map[enemy.y - 1][enemy.x] != 'E' && map[enemy.y
			- 1][enemy.x] != 'X')
			enemy.y--;
	}
	else if (player.x > enemy.x)
	{
		if (map[enemy.y][enemy.x + 1] != '1' && map[enemy.y][enemy.x + 1] != 'C'
			&& map[enemy.y][enemy.x + 1] != 'E' && map[enemy.y][enemy.x
			+ 1] != 'X')
			enemy.x++;
	}
	else if (player.x < enemy.x)
	{
		if (map[enemy.y][enemy.x - 1] != '1' && map[enemy.y][enemy.x - 1] != 'C'
			&& map[enemy.y][enemy.x - 1] != 'E' && map[enemy.y][enemy.x
			- 1] != 'X')
			enemy.x--;
	}
	return (enemy);
}
