/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:30:50 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/08 14:05:21 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_message(char *message, t_game **game)
{
	free_map(game);
	ft_printf("%s", message);
	exit (0);
}

void	free_map(t_game **game)
{
	int	x;

	x = 0;
	if (!(*game)->map)
	{
		while (x < (*game)->max_y)
			free((*game)->map[x++]);
	}
}

char	*ft_strndup(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_str_join(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i])
			str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

int	exit_hook(t_game **game)
{
	int	x;

	x = 0;
	while (x < (*game)->max_y)
		free((*game)->map[x++]);
	x = 0;
	while (x < 6)
		free((*game)->player[x++]);
	x = 0;
	while (x < 4)
		free((*game)->coin[x++]);
	mlx_destroy_window((*game)->mlx, (*game)->window);
	free((*game)->map);
	free((*game)->rock);
	free((*game)->exit);
	free((*game)->bg);
	exit(0);
}
