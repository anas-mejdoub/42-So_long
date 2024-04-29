/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:56:57 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 16:07:21 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include <mlx.h>

int						check_exit(char **map);
int						check_walls(char **map);
int						check_rectangular(char **map);
int						check_position(char **map);
int						check_collect(char **map);
char					**map_parsing(char *file_name);
void					free2d(char **str);
int						get_map_height(char **map);
int						get_map_width(char **map);
int						floodfill(char **map);
int						is_filled(char **map);
int						get_map_height(char **map);
int						get_map_width(char **map);
void					remove_nl(char **map);
int						check_wall_helper(int i, int j, int last, char **map);
int						check_execp(char **map);
int						check_extension(char *filename);
void					printf_err(void);

typedef struct s_point
{
	int					y;
	int					x;
}						t_point;

typedef struct s_img
{
	void				*player_r;
	void				*player_u;
	void				*player_d;
	void				*player_f;
	void				*player_l;
	void				*outer_wall;
	void				*inner_wall;
	void				*floor;
	void				*door;
	void				*opened_door;
	void				*coin;
	void				*coin2;
	void				*coin3;
	void				*coin4;
	void				*coin5;
	void				*floor_counter;
	void				*upper_counter;
	void				*naruto_up;
	void				*enemy_up;
	void				*enemy_right;
	void				*enemy_left;
	void				*enemy_down;
	void				*sprint_right;
	void				*sprint_left;
}						t_img;

typedef struct s_env
{
	t_img				img;
	void				*win;
	void				*mlx;
}						t_env;

typedef struct s_coins
{
	t_point				c_pos;
	void				*img;
	struct s_coins		*next;
}						t_coins;

enum
{
	GAME_START = 0,
	GAME_IN = 1,
	GAME_END = 2,
};

enum
{
	LOSE = 0,
	WIN = 1,
};
typedef struct s_var
{
	char				**map;
	t_env				*env;
	t_point				*p_pos;
	int					game_state;
	int					win;
}						t_var;

typedef struct s_enemies
{
	t_point				e_pos;
	void				*img;
	struct s_enemies	*next;
}						t_enemies;

typedef struct s_coins_var
{
	t_enemies			*enemies;
	t_coins				*coins;
	t_var				*var;
}						t_coins_var;
int						check_collect(char **map);
int						render_map(t_coins_var *variable);
void					handle_right_move(t_var *var, int *move);
void					handel_down_move(t_var *var, int *move);
void					handle_right_move(t_var *var, int *move);
void					handle_up_move(t_var *var, int *move);
int						movment_handler(int keycode, t_var *var);
void					render_helper(t_var var, int i, int y, t_point point);
int						open_images(t_env *env, int *width, int *height);
int						open_window_images(t_var *var);
void					game_start(t_var *var);
int						closing_game(t_var *var);
int						close_lose(t_var *var);
int						close_win(t_var *var);
int						render_coins(t_coins_var *variable);
int						check_c(t_coins_var *variable);
void					img_value(t_coins_var variable);
int						open_coins(t_env *env, int *width, int *height);
int						check_coins_assetes(t_env *env);
void					render_coins_helper(t_coins_var *variable);
void					fill_coins(t_coins_var *variable);
void					add_coins_back(t_coins **lst, t_point pos);
void					render_exit(t_var *var, t_point *point);
void					build_outer_wall(char **map, t_point p, t_point p2,
							t_env *env);
void					destroy_images(t_env *env, int n);
int						open_images(t_env *env, int *width, int *height);
t_point					item_postion(char **map, char c);
int						check_winner(char **map);
int						check_assets(t_env *env);
void					intialcounter(t_var *var);
void					build_counter_z(t_var *var);
int						closing_game(t_var *var);
void					handle_enemy(t_coins_var *variable);
int						open_enemy(t_env *env, int *width, int *height);
void					handle_enemy_handler(t_coins_var *variable,
							t_point pos);
void					game_start(t_var *var);
t_coins					*last_coin(t_coins *lst);
int						check_enemy_assets(t_env *env);
t_enemies				*last_enemy(t_enemies *lst);
void					add_enemies_back(t_enemies **lst, t_point pos);
void					fill_enemies(t_coins_var *variable);
void					enemies_img_intial(t_coins_var variable);
void					enemy_caller(t_coins_var *variable);
void					*ask_for_img(t_coins_var *variable);
int						red_cross(t_var *var);
t_point					search_p(t_coins_var *variable, t_point enemy);
void					handle_door(t_var *var, int *move, t_point new,
							void *pimg);
void					handle_win(t_var *var);
void					handle_free_move(t_var *var, int *move, t_point new,
							void *pimg);
void					up_down_move(t_var *var, int *move, t_point new,
							void *pimg);
void					change_door(t_var *var);
#endif