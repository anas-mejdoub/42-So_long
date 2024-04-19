/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:54:03 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/19 17:54:36 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c > 1 || c == 0)
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = get_map_width(map) - 1;
	if (!check_wall_helper(i, j, last, map))
		return (0);
	last = get_map_height(map) - 1;
	i = 0;
	while (map[last] && map[last][i])
	{
		if (map[last][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectangular(char **map)
{
	int	width;
	int	i;

	width = get_map_width(map);
	i = 0;
	while (map && map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	check_position(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				c++;
			j++;
		}
		i++;
	}
	if (c > 1 || c == 0)
		return (0);
	return (1);
}

int	check_collect(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
