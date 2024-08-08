/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:55:48 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/08 12:48:48 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free(char **str)
{
	char	**ptr;
	int		i;

	i = 0;
	if (!str)
		return ;
	ptr = str;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(str);
}

void	ft_exit(t_game_core *game)
{
	mlx_terminate(game->id);
	ft_free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}

void	ft_puterrorstr(char *str, t_game_core *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	if (game)
		ft_exit(game);
	exit(EXIT_FAILURE);
}
