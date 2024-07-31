/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/31 18:10:13 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game_core	*ft_prepare_game_core(mlx_t *id, char *map)
{
	t_game_core		*game;

	game->id = id;
	game->map = ft_read_map(game, map);
	ft_check_map(game, "P"); //Dentro busco P y guardo su X e Y en game
	ft_load_img(game); //Dentro cargo todos los png, los convierto a img y guardo
}

t_game_state	*ft_prepare_character(mlx_t *id, mlx_image_t *ig, int x, int y)
{
	t_game_state	*state;

	state = malloc(sizeof(t_game_state));
	if (!state)
		ft_puterrorstr("Error: No se pudo asignar memoria a t_game_state");
	state->id = id;
	state->image = ig;
	state->pos_x = x;
	state->pos_y = y;
	return (state);
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
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_game_state	*pc;
	t_game_core		*game;

	id = mlx_init(1920, 1080, "so_long", true);
	if (!id)
		ft_puterrorstr("Error: No se pudo iniciar identifier\n");
	game = ft_prepare_game_core(id, argv[1]);
	texture = mlx_load_png("/home/aarenas-/Desktop/so_long/img/player_x1.png");
	if (!texture)
		ft_puterrorstr("Error: No se pudo cargar la textura\n");
	image = mlx_texture_to_image(id, texture);
	if (!image)
		ft_puterrorstr("Error: No se pudo cargar la imagen\n");
	pc = ft_prepare_character(id, image, 400, 300);
	mlx_loop_hook(id, &render, pc);
	mlx_key_hook(id, &ft_controls_hook, pc);
	mlx_loop(id);
	mlx_terminate(id);
	return (EXIT_SUCCESS);
}
