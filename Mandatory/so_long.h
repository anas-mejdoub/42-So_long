/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:56:57 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/22 16:25:22 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include <mlx.h>

int			check_exit(char **map);
int			check_walls(char **map);
int			check_rectangular(char **map);
int			check_position(char **map);
int			check_collect(char **map);
char		**map_parsing(char *file_name);
void		free2d(char **str);
int			get_map_height(char **map);
int			get_map_width(char **map);
int			floodfill(char **map);
int			is_filled(char **map);
int			get_map_height(char **map);
int			get_map_width(char **map);
void		remove_nl(char **map);
int			check_wall_helper(int i, int j, int last, char **map);
typedef struct s_point
{
	int		y;
	int		x;
}			t_point;

typedef struct s_img
{
	void	*player_r;
	void	*player_u;
	void	*player_d;
	void	*player_f;
	void	*player_l;
	void	*outer_wall;
	void	*inner_wall;
	void	*floor;
	void	*door;
	void	*opened_door;
	void	*coin;
}			t_img;

typedef struct s_env
{
	t_img	img;
	void	*win;
	void	*mlx;
}			t_env;

typedef struct s_var
{
	char	**map;
	t_env	*env;
	t_point	*p_pos;
}			t_var;
int			check_collect(char **map);
int			render_map(char **map, t_env *env, void *player_dir,
				t_point *p_pos);
void		handle_right_move(t_var *var, int *move);
void		handel_down_move(t_var *var, int *move);
void		handle_right_move(t_var *var, int *move);
void		handle_up_move(t_var *var, int *move);
int			movment_handler(int keycode, t_var *var);
void		render_helper(t_var var, int i, int y, t_point point);
void		render_exit(t_var *var, t_point *point);
void		build_outer_wall(char **map, t_point p, t_point p2, t_env *env);
void		destroy_images(t_env *env, int n);
int			open_images(t_env *env, int *width, int *height, char **map);
t_point		item_postion(char **map, char c);
int			check_winner(char **map);
int			check_assets(t_env *env);
int	closing_game(t_var *var);
int	check_execp(char **map);
#endif