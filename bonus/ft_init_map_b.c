/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:32:29 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/08 14:05:36 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	*ft_read_map(t_game **game, int fd)
{
	int			rd_bytes;
	char		map[2048];
	char		*value;

	value = NULL;
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, map, 1);
		map[rd_bytes] = '\0';
		value = ft_str_join(value, map);
	}
	return (value);
}

bool	check_objects(t_game *game, int x, int y)
{
	int	*obj;

	obj = ft_calloc(3, sizeof(int));
	while (++y < game->max_y)
	{
		x = -1;
		while (++x < game->max_x)
		{
			if (game->map[y][x] == 'E')
				obj[0]++;
			else if (game->map[y][x] == 'C')
				obj[1]++;
			else if (game->map[y][x] == 'P')
				obj[2]++;
		}
	}
	if (obj[0] == 0 || obj[1] == 0 || obj[2] != 1)
	{
		free(obj);
		print_message("Gecersiz obje girisi !", &game);
	}
	free(obj);
	return (true);
}

bool	check_walls(t_game *game, int x, int y)
{
	int	count_x;

	while (++y < game->max_y)
	{
		x = -1;
		count_x = 0;
		while (++x < game->max_x)
		{
			if ((y == 0 || y == game->max_y - 1) && game->map[y][x] == '1')
				count_x++;
			if (!(ft_strchr("01CEPN", game->map[y][x])))
				print_message("Haritada gecersiz karakter !", &game);
			if ((x == 0 || x == game->max_x - 1) && game->map[y][x] != '1')
				print_message("Haritanin etrafi kapali olmalidir !", &game);
		}
		if ((y == 0 || y == game->max_y - 1) && count_x != game->max_x)
			print_message("Haritanin etrafi kapali olmalidir- !", &game);
		else if (ft_strlen(game->map[y]) != game->max_x)
			print_message("Gecersiz satir girisi !", &game);
	}
	return (check_objects(game, -1, -1));
}

bool	ft_init_map(t_game **game, char **argv)
{
	int		fd;
	char	*map;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		print_message("Dosya acilamadi !", game);
	map = ft_read_map(game, fd);
	(*game)->map = ft_split_fs(map, "\n", &(*game)->max_y);
	free(map);
	close(fd);
	(*game)->max_x = ft_strlen((*game)->map[0]);
	if ((*game)->max_x == (*game)->max_y)
		print_message("Harita kare olamaz", game);
	if (!(check_walls(*game, -1, -1)))
		return (false);
	return (ft_create_map(game));
}
