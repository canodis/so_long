/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:28:07 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/07 16:41:33 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(t_game **game, int x, int y)
{
	ft_mlx_put_image(game, (*game)->bg, (*game)->player_x, (*game)->player_y);
	ft_mlx_put_image(game, (*game)->player, (*game)->player_x + x,
		(*game)->player_y + y);
	(*game)->map[(*game)->player_y][(*game)->player_x] = '0';
	(*game)->map[(*game)->player_y + y][(*game)->player_x + x] = 'P';
	(*game)->player_x += x;
	(*game)->player_y += y;
	(*game)->player_move++;
	ft_printf("\33[2K\rHamle sayisi : %i", (*game)->player_move);
}

void	ft_ismove(t_game **game, int x, int y)
{
	if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == '0')
		ft_move(game, x, y);
	else if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == 'C')
	{
		ft_move(game, x, y);
		(*game)->coin_count--;
	}
	else if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == 'E')
	{
		if ((*game)->coin_count == 0)
		{
			ft_printf(" *_* TEBRIKLER *_*");
			exit_hook(game);
		}
		else
			ft_printf("\33[2K\rDaha %i tane obje var !", (*game)->coin_count);
	}
	else if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == 'N')
	{
		ft_printf(" *_* KAYBETTIN! *_*");
		exit_hook(game);
	}
	else
		ft_printf("\33[2K\rKoskoca duvari goremiyon mu ??????????");
}

int	ft_key_events(int key_code, t_game **game)
{
	if (key_code == KEY_ESC)
		exit_hook(game);
	else if (key_code == KEY_A)
		ft_ismove(game, -1, 0);
	else if (key_code == KEY_D)
		ft_ismove(game, 1, 0);
	else if (key_code == KEY_W)
		ft_ismove(game, 0, -1);
	else if (key_code == KEY_S)
		ft_ismove(game, 0, 1);
	return (0);
}
