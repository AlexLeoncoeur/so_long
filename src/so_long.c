/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/07 13:20:12 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_moves(t_game_core *game)
{
	ft_printf("%d\n", game->pc_moves);
}

t_game_core	*ft_prepare_game_core(mlx_t *id, char *map)
{
	t_game_core		*game;

	game = (t_game_core *)malloc(sizeof(t_game_core));
	if (game == NULL)
		ft_puterrorstr("Error: Could not allocate memory for game\n", NULL);
	game->id = id;
	game->map_row = 0;
	ft_read_map(game, map);
	ft_check_map(game, 'P');
	ft_load_img(game);
	game->pc_moves = 0;
	return (game);
}

int	main(int argc, char **argv)
{
	mlx_t			*id;
	t_game_core		*game;

	if (argc != 2)
		ft_puterrorstr("Error: .ber file needed\n", NULL);
	id = mlx_init(1920, 1080, "so_long", true);
	if (!id)
		ft_puterrorstr("Error: could not initializate identifier\n", NULL);
	game = ft_prepare_game_core(id, argv[1]);
	mlx_loop_hook(id, &ft_render_map, game);
	mlx_key_hook(id, &ft_controls_hook, game);
	mlx_loop(id);
	mlx_terminate(id);
	return (EXIT_SUCCESS);
}
