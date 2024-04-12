/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:41:41 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/12 16:55:15 by amejdoub         ###   ########.fr       */
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

char **add_str(char **vector, char *str)
{
    int i = 0;
    char **new_vector;
    new_vector = NULL;
    while (vector && vector[i])
    {
        i++;
    }
    new_vector = malloc(sizeof(char *) * (i + 2));
    if (!new_vector)
        return (NULL);
    i = 0;
    while (vector && vector[i])
    {
        ft_printf("%d\n", ft_strlen(vector[i]) -1);
        int len = ft_strlen(vector[i]);
        new_vector[i] =  ft_substr( vector[i], 0, len - 1);
        i++;
    }
    new_vector[i] = ft_substr( str, 0, ft_strlen(str));
    new_vector[i + 1] = NULL;
    // free2d(vector);
    return new_vector;
}

int map_parsing()
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
    i = 0;
    while (map[i])
    {
        ft_printf("hh %s\n", map[i]);
        i++;
    }
    return 0;
}
