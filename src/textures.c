/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:59:28 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/01 17:55:39 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_img(t_game_core *game)
{
	mlx_texture_t	*pc;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*resource;

	pc = mlx_load_png("/home/aarenas-/Desktop/so_long/img/player_x1.png");
	wall = mlx_load_png("/home/aarenas-/Desktop/so_long/img/player_x1.png");
	floor = mlx_load_png("/home/aarenas-/Desktop/so_long/img/player_x1.png");
	resource = mlx_load_png("/home/aarenas-/Desktop/so_long/img/player_x1.png");
	if (!pc || !wall || !floor || !resource)
		ft_puterrorstr("Error: No se pudo cargar la textura\n");
	game->pc_img = mlx_texture_to_image(game->id, pc);
	game->wall_img = mlx_texture_to_image(game->id, wall);
	game->floor_img = mlx_texture_to_image(game->id, floor);
	game->resource_img = mlx_texture_to_image(game->id, resource);
	if (!game->pc_img || !game->wall_img || !game->floor_img
		|| !game->resource_img)
		ft_puterrorstr("Error: No se pudo cargar la imagen\n");
}
