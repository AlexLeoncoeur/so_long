/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/08 18:16:54 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_game_size(t_game_core *g)
{
	float			scale_x;
	float			scale_y;

	g->map_w = ft_strlen(g->map[0]);
	g->map_h = g->map_row;
	scale_x = (float)g->id->width / (g->map_w * 32);
	scale_y = (float)g->id->height / (g->map_h * 32);
	if (scale_x < scale_y)
		g->scale = scale_x;
	else
		g->scale = scale_y;
	g->offset_x = (g->id->width - (g->map_w * 32 * g->scale)) / 2;
	g->offset_y = (g->id->height - (g->map_h * 32 * g->scale)) / 2;
}

void	ft_win_game(t_game_core *game)
{
	ft_printf("You won!\nYour total moves were: %d\n", game->pc_moves);
	mlx_terminate(game->id);
	ft_free(game->map);
	free(game);
	exit(EXIT_SUCCESS);
}

void	ft_print_moves(t_game_core *game)
{
	ft_printf("%d\n", game->pc_moves);
}

void	ft_prepare_game_core(mlx_t *id, t_game_core *game)
{
	game->id = id;
	ft_check_map(game, 'P');
	game->vp = 0;
	ft_check_vp(game);
	ft_load_img(game);
	ft_game_size(game);
	game->pc_moves = 0;
}

int	main(int argc, char **argv)
{
	mlx_t			*id;
	t_game_core		*game;

	if (argc != 2)
		ft_puterrorstr("Error: .ber file needed\n", NULL);
	game = (t_game_core *)malloc(sizeof(t_game_core));
	if (game == NULL)
		ft_puterrorstr("Error: Could not allocate memory for game\n", NULL);
	game->map_row = 0;
	ft_read_map(game, argv[1]);
	printf("x = %zu\ny = %d\n", ft_strlen(game->map[0]), game->map_row);
	id = mlx_init(ft_strlen(game->map[0]) * 64, game->map_row * 64, "so_long", true);
	if (!id)
		ft_puterrorstr("Error: could not initializate identifier\n", NULL);
	ft_prepare_game_core(id, game);
	mlx_loop_hook(id, &ft_render_map, game);
	mlx_key_hook(id, &ft_controls_hook, game);
	mlx_loop(id);
	ft_exit(game);
	return (EXIT_SUCCESS);
}
