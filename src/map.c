/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:35:33 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/07 13:39:07 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_read_map(t_game_core *game, char *map)
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
	game->map = ft_split(full_map, '\n');
	if (!game->map)
		ft_puterrorstr("Error: Could not load map\n", game);
	free(full_map);
	free(line);
	close(fd);
}

void	ft_check_map(t_game_core *game, char c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
			{
				game->pc_y = i;
				game->pc_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_puterrorstr("Error: Could not find player\n", game);
}

void	ft_render_map(void *param)
{
	t_game_core	*game;
	int			i;
	int			j;

	game = (t_game_core *)param;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_image_to_window(game->id, game->floor_img, j * 32, i * 32);
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->id, game->pc_img, j * 32, i * 32);
			if (game->map[i][j] == 'W')
				mlx_image_to_window(game->id, game->wall_img, j * 32, i * 32);
			if (game->map[i][j] == 'R')
				mlx_image_to_window(game->id, game->resource_img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

	/* i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			printf("%c", game->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("pcy: %d pcx: %d\n", game->pc_y, game->pc_x); */