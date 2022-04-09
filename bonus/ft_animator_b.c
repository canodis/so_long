/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animator_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:14:08 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/08 13:19:17 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_anim(t_game **game, int x, int y, char type)
{
	if (type == 'P')
	{
		ft_mlx_put_image(game, (*game)->player[(*game)->p_anim], x, y);
		(*game)->p_anim++;
		if ((*game)->p_anim >= 6)
			(*game)->p_anim = 0;
	}
	else if (type == 'C')
	{
		if ((*game)->c_anim >= 4)
			(*game)->c_anim = 0;
		ft_mlx_put_image(game, (*game)->coin[(*game)->c_anim], x, y);
	}
}

static void	ft_isanim(t_game **game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (*game)->max_y)
	{
		x = -1;
		while (++x < (*game)->max_x)
		{
			if ((*game)->map[y][x] == 'P')
				ft_anim(game, x, y, 'P');
			else if ((*game)->map[y][x] == 'C')
				ft_anim(game, x, y, 'C');
		}
	}
	(*game)->c_anim++;
}

static void	ft_move_enemy(t_game **game, int x, int y)
{
	if ((*game)->map[y][x + 1] == 'P' || (*game)->map[y][x - 1] == 'P')
		exit_hook(game);
	else if ((*game)->map[y][x + 1] == '0')
	{
		ft_mlx_put_image(game, (*game)->enemy, x + 1, y);
		ft_mlx_put_image(game, (*game)->bg, x, y);
		(*game)->map[y][x] = '0';
		(*game)->map[y][x + 1] = 'N';
	}
	else
	{
		ft_mlx_put_image(game, (*game)->bg, x, y);
		(*game)->map[y][x] = '0';
		while ((*game)->map[y][x] != '1' && x)
			x--;
		if ((*game)->map[y][x + 1] == 'P')
			exit_hook(game);
		ft_mlx_put_image(game, (*game)->enemy, x + 1, y);
		(*game)->map[y][x + 1] = 'N';
	}
}

static void	ft_ismove_enemy(t_game **game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (*game)->max_y)
	{
		x = -1;
		while (++x < (*game)->max_x)
		{
			if ((*game)->map[y][x] == 'N')
			{
				ft_move_enemy(game, x, y);
				x++;
			}
		}
	}
}

int	ft_animator(t_game **game)
{
	(*game)->anim_counter++;
	(*game)->enemy_speed++;
	if ((*game)->anim_counter >= 1500)
	{
		ft_isanim(game);
		(*game)->anim_counter = 0;
	}
	if ((*game)->enemy_speed >= 3000)
	{
		ft_ismove_enemy(game);
		(*game)->enemy_speed = 0;
	}
	return (0);
}
