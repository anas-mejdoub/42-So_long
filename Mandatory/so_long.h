/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:56:57 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/17 19:34:14 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"
#include <mlx.h>
char **map_parsing(char *file_name);
void	free2d(char **str);
int get_map_height(char **map);
int get_map_width(char **map);
int floodfill(char **map);
int is_filled(char **map);
int	get_map_height(char **map);
int	get_map_width(char **map);
typedef struct	s_point
{
	int			y;
	int			x;
}		t_point;

typedef struct s_img
{
	void *player_r;
	void *player_u;
	void *player_d;
	void *player_f;
	void *player_l;
	void *outer_wall;
	void *inner_wall;
	void *floor;
	void *door;
	void *opened_door;
	void *coin;
}	t_img;

typedef struct s_env
{
	t_img img;
	void *win;
	void *mlx;
} t_env;

typedef struct s_var
{
	char **map;
	t_env *env;
	t_point *p_pos;
} t_var;
int	check_collect(char **map);
int render_map(char **map, t_env *env, void *player_dir, t_point *p_pos);
#endif