/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:41:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 16:07:57 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free2d(char **str)
{
    int i = 0;
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

int check_collect(char **map)
{
    int i = 0;
    int j;
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
    return 0;
}
int check_position(char **map)
{
    int i = 0;
    int j;
    int c = 0;
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
    if (c > 1)
        return 0;
    return 1;
}

int get_map_width(char **map)
{
    int i = 0;
    while (map[0][i])
        i++;
    return (i);
}

int get_map_height(char **map)
{
    int i = 0;
    while (map[i])
        i++;
    return i;
}

int check_rectangular(char **map)
{
    int width = get_map_width(map);
    int i = 0;
    while (map && map[i])
    {
        if ((int )ft_strlen(map[i]) != width)
            return 0;
        i++;
    }
    return (1);
}

int check_walls(char **map)
{
    int i = 0;
    int j = 0;
    int last = get_map_width(map) - 1;
    while (map[i][j])
    {
        if (map[i][j] != '1')
            return 0;
        j++;
    }
    i = 0;
    while (map[i] && map[i][0])
    {
        if (map[i][0] != '1')
            return 0;
        i++;
    }
    i = 0;
    while (map[i] && map[i][last])
    {
        if (map[i][last] != '1')
            return 0;
        i++;
    }
    last = get_map_height(map) - 1;
    i = 0;
    while (map[last] && map[last][i])
    {
        if (map[last][i] != '1')
            return 0;
        i++;
    }
    return (1);
}
int check_exit(char **map)
{
    int i = 0;
    int j;
    int c = 0;
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
    if (c > 1)
        return 0;
    return 1;
}

void remove_nl(char **map)
{
    int i = 0;
    while (map[i + 1])
    {
        map[i] = ft_substr2(map[i], 0, ft_strlen(map[i]) - 1, 'f');
        i++;
    }
}

char **add_str(char **map, char *str)
{
    int i = 0;
    char **new_map;
    new_map = NULL;
    while (map && map[i])
    {
        i++;
    }
    new_map = malloc(sizeof(char *) * (i + 2));
    if (!new_map)
        return (NULL);
    i = 0;
    while (map && map[i])
    {
        new_map[i] =  map[i];
        i++;
    }
    new_map[i] = str;
    new_map[i + 1] = NULL;
    free(map);
    return new_map;
}
int check_map_error(char **map)
{
    if (check_exit(map) && check_position(map) && check_walls(map) && check_collect(map) && check_rectangular(map))
        return 1;
    return 0;
}
char **map_parsing()
{
    char **map;
    char *str;
    int fd = open ("./maps/map1.ber", O_RDONLY);
    map = NULL;
    if (fd == -1)
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    str = get_next_line(fd);
    while (str)
    {
        map = add_str(map, str);
        str = get_next_line(fd);
    }
    remove_nl(map);
    if (!check_map_error(map))
        return (NULL);
    return map;
}

