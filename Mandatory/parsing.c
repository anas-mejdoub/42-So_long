/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:41:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 14:39:17 by amejdoub         ###   ########.fr       */
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
int remove_nl(char **map)
{
    int i = 0;
    while (map[i + 1])
    {
        map[i] = ft_substr2(map[i], 0, ft_strlen(map[i]) - 1, 'f');
        i++;
    }
    return 1;
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

char **map_parsing()
{
    char **map;
    char *str;
    int fd = open ("../maps/map1.ber", O_RDONLY);
    map = NULL;
    if (fd == -1)
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    int i = 0;
    str = get_next_line(fd);
    while (str)
    {
        map = add_str(map, str);
        str = get_next_line(fd);
    }
    remove_nl(map);
    return map;
}
