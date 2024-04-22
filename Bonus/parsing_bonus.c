/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:41:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/22 16:23:12 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

char	**add_str(char **map, char *str)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	if (str)
		j = 1;
	new_map = NULL;
	while (map && map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1 + j));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	if (str)
		new_map[i++] = str;
	new_map[i] = NULL;
	free(map);
	return (new_map);
}

char	**dup2d(char **map)
{
	int		i;
	char	**dup_map;

	i = 0;
	while (map[i])
		i++;
	dup_map = malloc(sizeof(char *) * (i + 1));
	if (!dup_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup_map[i] = strdup(map[i]);
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

int	check_map_error(char **map)
{
	if (check_exit(map) && check_position(map) && check_walls(map)
		&& check_collect(map) && check_rectangular(map)
		&& floodfill(dup2d(map)) && check_execp(map))
		return (1);
	return (0);
}

char	**map_parsing(char *file_name)
{
	char	**map;
	char	*str;
	int		fd;

	fd = open(file_name, O_RDONLY);
	map = NULL;
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	str = get_next_line(fd);
	while (str)
	{
		map = add_str(map, str);
		str = get_next_line(fd);
	}
	remove_nl(map);
	if (!check_map_error(map))
		return (close(fd), free2d(map), NULL);
	close(fd);
	return (map);
}
