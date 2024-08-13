/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscelaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:13:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/13 16:06:08 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_open_file(t_game_core *game, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_puterrorstr("Error: Failed to open map file\n", game);
	return (fd);
}

size_t	ft_len_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_free_read_map(char *line, char *full_map, t_game_core *game)
{
	free(line);
	free(full_map);
	ft_puterrorstr("Error: Uneven map\n", game);
}

void	ft_set_game_core(t_game_core *g)
{
	g->id = 0;
	g->map_column = 0;
	g->map_row = 0;
	g->map = NULL;
	g->map_cpy = NULL;
}
