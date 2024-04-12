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

char **mini_vector(char **vector, char *str)
{
    int i = 0;
    char **new_vector;
    while (vector[i])
        i++;
    
}

int map_parsing()
{
    t_list *map;
    char *str;
    int fd = open ("../maps/map1.ber", O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    int i = 0;
    str = get_next_line(fd);
    while (str)
    {
        ft_lstadd_back(&map, ft_lstnew(str));
        str = get_next_line(fd);
        i++;
    }
    i = 0;
    while (map)
    {
        ft_printf("%s", map->content);
        map = map->next;
        i++;
    }
    return 0;
}
