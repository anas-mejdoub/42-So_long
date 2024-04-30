/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:14:13 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/30 11:56:49 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	get_position(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	is_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10X", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	free2d(map);
	return (1);
}

void	check_fill(char **map, t_point size, t_point current)
{
	if (current.x < 0 || current.x > size.x || current.y < 0
		|| current.y > size.y || map[current.y][current.x] == '1')
		return ;
	if (map[current.y][current.x] != '1')
		map[current.y][current.x] = '1';
	check_fill(map, size, (t_point){current.y - 1, current.x});
	check_fill(map, size, (t_point){current.y + 1, current.x});
	check_fill(map, size, (t_point){current.y, current.x - 1});
	check_fill(map, size, (t_point){current.y, current.x + 1});
}

int	floodfill(char **map)
{
	t_point	position;
	t_point	size;

	position = get_position(map);
	size = (t_point){get_map_height(map), get_map_width(map)};
	check_fill(map, size, position);
	return (is_filled(map));
}
