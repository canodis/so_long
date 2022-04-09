/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:38:52 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/08 14:18:35 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	check_name(char *name)
{
	char	*find;

	find = ft_strrchr(name, '.');
	if (!find || ft_strlen(find) != 4)
		return (false);
	if (ft_strncmp(find, ".ber", 4) == 0)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->m = 50;
	if (!game)
		return (0);
	if (argc != 2)
		print_message("Eksik veya fazla arguman girisi !", &game);
	if (!(check_name(argv[1])) || !(ft_init_map(&game, argv)))
		print_message("map yuklenemedi !", &game);
	game->player_move = 0;
	mlx_key_hook(game->window, ft_key_events, &game);
	mlx_hook(game->window, 17, 0, exit_hook, &game);
	mlx_loop(game->mlx);
	return (0);
}
