/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/30 15:58:50 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
} */

static void	ft_hook(void *param)
{
	const mlx_t	*mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

t_game_state	*ft_prepare_character(mlx_t *id, mlx_image_t *ig, int x, int y)
{
	t_game_state	*state;

	state = NULL;
	state->identifier = id;
	state->image = ig;
	state->pos_x = x;
	state->pos_y = y;
	return (state);
}

static void	render(void *param)
{
	t_game_state	*pc;

	pc = (t_game_state *)param;
	mlx_image_to_window(pc->identifier, pc->image, pc->pos_x, pc->pos_y);
}

int	main(void)
{
	mlx_t			*identifier;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_game_state	*pc;

	identifier = mlx_init(1920, 1080, "so_long", true);
	/* if (!identifier)
		ft_error(); */
	open("../img/players green x1.png", O_RDWR);
	texture = mlx_load_png("../img/players green x1.png");
	/* if (!image)
		ft_strerror("Error: No se pudo cargar la imagen\n"); */
	image = mlx_texture_to_image(identifier, texture);
	pc = ft_prepare_character(identifier, image, 400, 300);
	mlx_loop_hook(identifier, &render, pc);
	mlx_loop_hook(identifier, &ft_hook, identifier);
	mlx_key_hook(identifier, &ft_controls_hook, pc);
	mlx_loop(identifier);
	mlx_terminate(identifier);
	return (EXIT_SUCCESS);
}
