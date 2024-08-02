/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:45:27 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/02 12:53:16 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_move_up(t_game_core *game)
{
	char	swap;

	swap = game->map[game->pc_y][game->pc_x];
	game->map[game->pc_y][game->pc_x] = game->map[game->pc_y + 1][game->pc_x];
	game->map[game->pc_y + 1][game->pc_x] = swap;
	game->pc_y++;
}

static void	ft_move_down(t_game_core *game)
{
	char	swap;

	swap = game->map[game->pc_y][game->pc_x];
	game->map[game->pc_y][game->pc_x] = game->map[game->pc_y - 1][game->pc_x];
	game->map[game->pc_y + 1][game->pc_x] = swap;
	game->pc_y--;
}

static void	ft_move_left(t_game_core *game)
{
	char	swap;

	swap = game->map[game->pc_y][game->pc_x];
	game->map[game->pc_y][game->pc_x] = game->map[game->pc_y][game->pc_x - 1];
	game->map[game->pc_y][game->pc_x - 1] = swap;
	game->pc_x--;
}

static void	ft_move_right(t_game_core *game)
{
	char	swap;

	swap = game->map[game->pc_y][game->pc_x];
	game->map[game->pc_y][game->pc_x] = game->map[game->pc_y][game->pc_x + 1];
	game->map[game->pc_y][game->pc_x + 1] = swap;
	game->pc_x++;
}

void	ft_controls_hook(mlx_key_data_t keydata, void *param)
{
	t_game_core	*game;

	game = (t_game_core *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->id);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_move_up(game);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_move_down(game);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_move_left(game);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			ft_move_right(game);
	}
}
