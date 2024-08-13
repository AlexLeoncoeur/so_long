/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/13 15:14:47 by aarenas-         ###   ########.fr       */
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
	ft_free(game->map_cpy);
	free(game);
	exit(EXIT_SUCCESS);
}

void	ft_print_moves(t_game_core *game)
{
	ft_printf("%d\n", game->pc_moves);
}

void	ft_prepare_game_core(t_game_core *game)
{
	game->id = NULL;
	game->c = 0;
	game->vp = 0;
	ft_check_map_error(game);
	ft_check_map_component(game);
	ft_check_map(game, 'P');
	ft_check_walls(game);
	ft_check_vp(game);
	ft_flood_prep(game);
	game->pc_moves = 0;
}

int	main(int argc, char **argv)
{
	mlx_t			*id;
	t_game_core		*g;

	if (argc != 2 || ft_check_argv(argv[1]) == 1)
		ft_puterrorstr("Error: .ber file needed\n", NULL);
	g = (t_game_core *)malloc(sizeof(t_game_core));
	if (g == NULL)
		ft_puterrorstr("Error: Could not allocate memory for game\n", NULL);
	ft_set_game_core(g);
	ft_read_map(g, argv[1]);
	ft_prepare_game_core(g);
	id = mlx_init(ft_strlen(g->map[0]) * 64, g->map_row * 64, "so_long", true);
	if (!id)
		ft_puterrorstr("Error: could not initializate identifier\n", NULL);
	g->id = id;
	ft_load_img(g);
	ft_game_size(g);
	ft_render_map(g);
	mlx_resize_hook(id, ft_resize, NULL);
	mlx_key_hook(id, &ft_controls_hook, g);
	mlx_loop(id);
	ft_exit(g);
	return (EXIT_SUCCESS);
}
