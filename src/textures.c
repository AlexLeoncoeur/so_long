/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:59:28 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/12 16:34:33 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_textures(mlx_texture_t	*a, mlx_texture_t	*b)
{
	free(a);
	free(b);
}

void	ft_load_img(t_game_core *g)
{
	mlx_texture_t	*pc;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;

	pc = mlx_load_png("/home/aarenas-/Desktop/so_long2/textures/sans.png");
	wall = mlx_load_png("/home/aarenas-/Desktop/so_long2/textures/wall.png");
	floor = mlx_load_png("/home/aarenas-/Desktop/so_long2/textures/floor.png");
	coin = mlx_load_png("/home/aarenas-/Desktop/so_long2/textures/coin.png");
	exit = mlx_load_png("/home/aarenas-/Desktop/so_long2/textures/exit.png");
	if (!pc || !wall || !floor || !coin || !exit)
		ft_exit(g);
	g->pc_img = mlx_texture_to_image(g->id, pc);
	g->wall_img = mlx_texture_to_image(g->id, wall);
	g->floor_img = mlx_texture_to_image(g->id, floor);
	g->rsc_img = mlx_texture_to_image(g->id, coin);
	g->exit_img = mlx_texture_to_image(g->id, exit);
	if (!g->pc_img || !g->wall_img || !g->floor_img || !g->rsc_img
		|| !g->exit_img)
		ft_puterrorstr("Error: Could not load image\n", g);
	ft_free_textures(pc, wall);
	ft_free_textures(floor, coin);
	free(exit);
}
