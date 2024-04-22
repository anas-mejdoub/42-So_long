/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/22 17:02:56 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point search_p(char **map, t_point enemy, t_point player)
{
    if (player.y > enemy.y)
    {
        if (map[enemy.y + 1][enemy.x] != '1' && map[enemy.y + 1][enemy.x] != 'C')
            enemy.y++;
    }
    else if (player.y < enemy.y)
    {
        if (map[enemy.y - 1][enemy.x] != '1' && map[enemy.y - 1][enemy.x] != 'C')
            enemy.y--;
    }
    else if (player.x > enemy.x)
    {
        if (map[enemy.y][enemy.x + 1] != '1' && map[enemy.y][enemy.x + 1] != 'C')
            enemy.x++;
    }
    else if (player.x < enemy.x)
    {
        if (map[enemy.y][enemy.x - 1] != '1' && map[enemy.y][enemy.x - 1] != 'C')
            enemy.x--;
    }
    ft_printf("enemy.x : %d | enemy.y : %d || player.x : %d | player.y : %d\n", enemy.x, enemy.y, player.x, player.y);
    return (enemy);
}
