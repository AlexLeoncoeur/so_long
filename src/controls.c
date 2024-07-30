/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:45:27 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/30 15:14:31 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_controls_hook(mlx_key_data_t keydata, void *param)
{
	t_game_state	*state;

	state = (t_game_state *)param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			state->pos_y -= 10;
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			state->pos_y += 10;
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			state->pos_x -= 10;
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			state->pos_x += 10;
	}
}
