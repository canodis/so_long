/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:07:10 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/08 14:08:40 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "stdbool.h"
# include "fcntl.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_K 40

typedef struct l_game
{
	char	**map;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		m;
	int		coin_count;
	int		player_move;
	int		enemy_speed;
	int		sprite_size;
	int		anim_counter;
	int		p_anim;
	int		c_anim;
	void	*window;
	void	*mlx;
	void	*player[6];
	void	*coin[4];
	void	*exit;
	void	*enemy;
	void	*bg;
	void	*rock;
}	t_game;

char	**ft_split_fs(char *str, char *charset, int *ln);
char	*ft_strndup(char *tmp, int len);
char	*ft_strndup(char *src, int j);
bool	ft_init_map(t_game **game, char **argv);
void	print_message(char *message, t_game **game);
bool	ft_create_map(t_game **game);
void	convertoxpm(t_game **game);
int		ft_key_events(int key_code, t_game **game);
void	ft_mlx_put_image(t_game **game, void *obj, int x, int y);
int		ft_animator(t_game **game);
char	*ft_str_join(char *left_str, char *buff);
int		exit_hook(t_game **game);
void	free_map(t_game **game);

#endif