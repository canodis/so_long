/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xpms_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:31:36 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/07 14:00:40 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	*mlx_to_image(t_game **game, char *path)
{
	return (mlx_xpm_file_to_image((*game)->mlx,
			path, &(*game)->sprite_size, &(*game)->sprite_size));
}

static void	convert_player(t_game **game)
{
	(*game)->player[0] = mlx_to_image(game, "sprites/player/0.xpm");
	(*game)->player[1] = mlx_to_image(game, "sprites/player/1.xpm");
	(*game)->player[2] = mlx_to_image(game, "sprites/player/2.xpm");
	(*game)->player[3] = mlx_to_image(game, "sprites/player/3.xpm");
	(*game)->player[4] = mlx_to_image(game, "sprites/player/4.xpm");
	(*game)->player[5] = mlx_to_image(game, "sprites/player/5.xpm");
}

static void	convert_collectible(t_game **game)
{
	(*game)->coin[0] = mlx_to_image(game, "sprites/coin/0.xpm");
	(*game)->coin[1] = mlx_to_image(game, "sprites/coin/1.xpm");
	(*game)->coin[2] = mlx_to_image(game, "sprites/coin/2.xpm");
	(*game)->coin[3] = mlx_to_image(game, "sprites/coin/3.xpm");
}

static void	convert_enemies(t_game **game)
{
	(*game)->enemy = mlx_to_image(game, "sprites/enemies/0.xpm");
}

void	convertoxpm(t_game **game)
{
	(*game)->exit = mlx_to_image(game, "sprites/exit.xpm");
	(*game)->bg = mlx_to_image(game, "sprites/background.xpm");
	(*game)->rock = mlx_to_image(game, "sprites/rock.xpm");
	convert_player(game);
	convert_collectible(game);
	convert_enemies(game);
}
