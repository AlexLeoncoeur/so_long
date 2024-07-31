/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:35:33 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/31 18:13:43 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_read_map(t_game_core *game, char *map)
{
	char	*full_map;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		full_map = ft_strjoin(full_map, line);
		free(line);
		line = get_next_line(fd);
		game->map_row++;
	}
	game->map = ft_split(full_map, "\n");
}
