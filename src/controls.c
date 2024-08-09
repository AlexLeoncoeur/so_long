/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:45:27 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:00:36 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_move_up(t_game_core *game)
{
	int	x;
	int	y;
	
	x = game->pc_x * (32 * game->scale + game->offset_x);
	y = game->pc_y * (32 * game->scale + game->offset_y);

	if (game->map[game->pc_y - 1][game->pc_x] == '1')
		return ;
	if (game->map[game->pc_y - 1][game->pc_x] == 'C')
		game->vp--;
	if (game->map[game->pc_y][game->pc_x + 1] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x, y - 1);
	else
		mlx_image_to_window(game->id, game->floor_img, x, y - 1);
	if (game->map[game->pc_y][game->pc_x] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x, y - 1);
	else
		mlx_image_to_window(game->id, game->floor_img, x, y);
	mlx_image_to_window(game->id, game->pc_img, x, y - 1);
	game->pc_y--;
	game->pc_moves++;
	ft_print_moves(game);
}

static void	ft_move_down(t_game_core *game)
{
	int	x;
	int	y;
	
	x = game->pc_x * (32 * game->scale + game->offset_x);
	y = game->pc_y * (32 * game->scale + game->offset_y);

	if (game->map[game->pc_y + 1][game->pc_x] == '1')
		return ;
	if (game->map[game->pc_y + 1][game->pc_x] == 'C')
		game->vp--;
	if (game->map[game->pc_y][game->pc_x + 1] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x, y + 1);
	else
		mlx_image_to_window(game->id, game->floor_img, x, y + 1);
	if (game->map[game->pc_y][game->pc_x] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x, y + 1);
	else
		mlx_image_to_window(game->id, game->floor_img, x, y);
	mlx_image_to_window(game->id, game->pc_img, x, y + 1);
	game->pc_y++;
	game->pc_moves++;
	ft_print_moves(game);
}

static void	ft_move_left(t_game_core *game)
{
	int	x;
	int	y;
	
	x = game->pc_x * (32 * game->scale + game->offset_x);
	y = game->pc_y * (32 * game->scale + game->offset_y);

	if (game->map[game->pc_y][game->pc_x - 1] == '1')
		return ;
	if (game->map[game->pc_y][game->pc_x - 1] == 'C')
		game->vp--;
	if (game->map[game->pc_y][game->pc_x + 1] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x - 1, y);
	else
		mlx_image_to_window(game->id, game->floor_img, x - 1, y);
	if (game->map[game->pc_y][game->pc_x] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x, y);
	else
		mlx_image_to_window(game->id, game->floor_img, x, y);
	mlx_image_to_window(game->id, game->pc_img, x - 1, y);
	game->pc_x--;
	game->pc_moves++;
	ft_print_moves(game);
}

static void	ft_move_right(t_game_core *game)
{
	int	x;
	int	y;
	
	x = game->pc_x * (32 * game->scale + game->offset_x);
	y = game->pc_y * (32 * game->scale + game->offset_y);

	if (game->map[game->pc_y][game->pc_x + 1] == '1')
		return ;
	if (game->map[game->pc_y][game->pc_x + 1] == 'C')
		game->vp--;
	if (game->map[game->pc_y][game->pc_x + 1] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x + 1, y);
	else
		mlx_image_to_window(game->id, game->floor_img, x + 1, y);
	if (game->map[game->pc_y][game->pc_x] == 'E')
		mlx_image_to_window(game->id, game->exit_img, x, y);
	else
		mlx_image_to_window(game->id, game->floor_img, x, y);
	mlx_image_to_window(game->id, game->pc_img, x + 1, y);
	game->pc_x++;
	game->pc_moves++;
	ft_print_moves(game);
}

void	ft_controls_hook(mlx_key_data_t keydata, void *param)
{
	t_game_core	*game;

	game = (t_game_core *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			ft_exit(game);
			mlx_close_window(game->id);
		}
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_move_up(game);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_move_down(game);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_move_left(game);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			ft_move_right(game);
	}
	if (game->vp == 0)
		ft_win_game(game);
}
