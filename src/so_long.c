/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:03 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/25 17:12:41 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 'Encodes' four individual bytes into an int.
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	get_a(int rgba)
{
	return (rgba & 0xFF);
}

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	ft_hook(void *param)
{
	const mlx_t	*mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(void)
{
	int			i;
	int			j;
	mlx_t		*identifier;
	mlx_image_t	*img;
	uint32_t	color;

	identifier = mlx_init(1920, 1080, "so_long", true);
	if (!identifier)
		ft_error();
	color = get_rgba(204, 140, 204, 1);
	img = mlx_new_image(identifier, 1920, 1080);
	uint32_t *pixels = (uint32_t *)img->pixels;
	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			pixels[i * 1920 + j] = color;
			j++;
		}
		i++;
	}
	mlx_image_to_window(identifier, img, 0, 0);
 	mlx_loop_hook(identifier, ft_hook, identifier);
	mlx_loop_hook(identifier, ft_controls_hook, identifier);
	mlx_loop(identifier);
	mlx_terminate(identifier);
	return (EXIT_SUCCESS);
}
