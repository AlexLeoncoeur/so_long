/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:55:48 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:59:32 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_walls(t_game_core *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[0][++j])
		if (game->map[0][j] != '1')
			ft_puterrorstr("Error: Walls dont cover map border\n", game);
	j = -1;
	while (game->map[game->map_row][++j])
		if (game->map[game->map_row][j] != '1')
			ft_puterrorstr("Error: Walls dont cover map border\n", game);
	i = -1;
	while (game->map[++i][0])
		if (game->map[++i][0] != '1')
			ft_puterrorstr("Error: Walls dont cover map border\n", game);
	i = -1;
	while (game->map[++i][ft_strlen(game->map[i])])
		if (game->map[++i][ft_strlen(game->map[i])] != '1')
			ft_puterrorstr("Error: Walls dont cover map border\n", game);
			
}

int	ft_check_argv(char *argv)
{
	int	size;
	
	size = ft_strlen(argv);
	if (argv[size - 3] != '.' || argv[size - 2] != 'b' || argv[size - 1] != 'e' 
		|| argv[size] != 'r')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
