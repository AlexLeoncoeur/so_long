/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:49:17 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/13 11:40:32 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_map_error(t_game_core *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
			{
				ft_puterrorstr("Error: Incorrect map\n", game);
			}
			j++;
		}
		i++;
	}
}

static void	ft_search_map(t_game_core *game, char c)
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
				return ;
			}
			j++;
		}
		i++;
	}
	ft_puterrorstr("Error: Could not find component\n", game);
}

void	ft_check_map_component(t_game_core *game)
{
	ft_search_map(game, '0');
	ft_search_map(game, '1');
	ft_search_map(game, 'P');
	ft_search_map(game, 'C');
	ft_search_map(game, 'E');
}

static int	ft_flood_fill(int i, int j, t_game_core *game)
{
	if (game->map_cpy[i][j] == '1' || game->map_cpy[i][j] == 'F')
		return (EXIT_FAILURE);
	else if (game->map_cpy[i][j] == 'C')
		game->c++;
	else if (game->map_cpy[i][j] == 'E')
		game->exit = 1;
	game->map_cpy[i][j] = 'F';
	ft_flood_fill(i, j + 1, game);
	ft_flood_fill(i, j - 1, game);
	ft_flood_fill(i + 1, j, game);
	ft_flood_fill(i - 1, j, game);
	if (game->c == game->vp && game->exit == 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	ft_flood_prep(t_game_core *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_cpy[i])
	{
		j = 0;
		while (game->map_cpy[i][j])
		{
			if (game->map_cpy[i][j] == 'P')
				if (ft_flood_fill(i, j, game) == 1)
					ft_puterrorstr("Error: Player cannot finish game\n", game);
			j++;
		}
		i++;
	}
}
