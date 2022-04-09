/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:40:15 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/03 17:08:56 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_mlx_put_image(t_game **game, void *obj, int x, int y)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->window,
		obj, x * (*game)->m, y * (*game)->m);
}

static void	ft_create_object(t_game **game, char obj, int x, int y)
{
	if (obj == '0')
		ft_mlx_put_image(game, (*game)->bg, x, y);
	else if (obj == '1')
		ft_mlx_put_image(game, (*game)->rock, x, y);
	else if (obj == 'P')
	{
		ft_mlx_put_image(game, (*game)->player[0], x, y);
		(*game)->player_x = x;
		(*game)->player_y = y;
	}
	else if (obj == 'C')
	{
		ft_mlx_put_image(game, (*game)->coin[0], x, y);
		(*game)->coin_count++;
	}
	else if (obj == 'E')
		ft_mlx_put_image(game, (*game)->exit, x, y);
	else if (obj == 'N')
		ft_mlx_put_image(game, (*game)->enemy, x, y);
}

bool	ft_create_map(t_game **game)
{
	int	x;
	int	y;

	(*game)->mlx = mlx_init();
	(*game)->coin_count = 0;
	(*game)->window = mlx_new_window((*game)->mlx, (*game)->max_x * (*game)->m,
			(*game)->max_y * (*game)->m, "So_Long");
	convertoxpm(game);
	y = -1;
	while (++y < (*game)-> max_y)
	{
		x = -1;
		while (++x < (*game)-> max_x)
		{
			ft_create_object(game, (*game)->map[y][x], x, y);
		}
	}
	return (true);
}
