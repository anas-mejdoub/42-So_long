/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:14:13 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 16:52:27 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point get_position(char **map)
{
    int i = 0;
    int j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                return ((t_point){i, j});
            j++;
        }
        i++;
    }
    return ((t_point){-1, -1});
}

int check_fill(char **map, t_point size, t_point current)
{
    if (current.x < 0 || current.x >= size.x || current.y < 0 || current.y >= size.y || map[current.y][current.x] == '1')
        return;
    map[current.y][current.x] = '1';
    check_fill()
}

int floodfill()
{
    char **temp = map_parsing();
    t_point position = get_position(temp);
    t_point size = {get_map_height(temp), get_map_width(temp)};
    
}