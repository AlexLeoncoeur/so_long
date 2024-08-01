/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/01 17:58:50 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game_core	*ft_prepare_game_core(mlx_t *id, char *map)
{
	t_game_core		*game;

	game->id = id;
	game->map_row = 0;
	game->map_col = 0;
	ft_read_map(game, map);
	ft_check_map(game, "P"); //Dentro busco P y guardo su X e Y en game
	ft_load_img(game); //Dentro cargo todos los png, los convierto a img y guardo
}

static void	render(void *param)
{
	t_game_state	*pc;

	pc = (t_game_state *)param;
	mlx_image_to_window(pc->id, pc->image, pc->pos_x, pc->pos_y);
}

int	main(int argc, char **argv)
{
	mlx_t			*id;
	t_game_state	*pc;
	t_game_core		*game;

	id = mlx_init(1920, 1080, "so_long", true);
	if (!id)
		ft_puterrorstr("Error: No se pudo iniciar identifier\n");
	game = ft_prepare_game_core(id, argv[1]);
	mlx_loop_hook(id, &render, pc);
	mlx_key_hook(id, &ft_controls_hook, pc);
	mlx_loop(id);
	mlx_terminate(id);
	return (EXIT_SUCCESS);
}
