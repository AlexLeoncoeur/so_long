/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:04:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/07 13:22:33 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game_state
{
	mlx_t			*id;
	mlx_image_t		*image;
	int				pos_x;
	int				pos_y;
}	t_game_state;

typedef struct s_game_core
{
	mlx_t		*id;
	char		**map;
	int			pc_y;
	int			pc_x;
	int			pc_moves;
	int			map_row;
	mlx_image_t	*pc_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*resource_img;
}	t_game_core;

/*-------------------- so_long --------------------*/
t_game_core		*ft_prepare_game_core(mlx_t *id, char *map);
void			ft_print_moves(t_game_core *game);
void			ft_load_img(t_game_core *game);

/*-------------------- map --------------------*/
void			ft_read_map(t_game_core *game, char *map);
void			ft_check_map(t_game_core *game, char c);
void			ft_render_map(void *param);

/*-------------------- textures --------------------*/
void			ft_load_img(t_game_core *game);

/*-------------------- Controls --------------------*/
void			ft_controls_hook(mlx_key_data_t keydata, void *param);

/*-------------------- Error --------------------*/
void			ft_puterrorstr(char *str, t_game_core *game);
void			ft_exit(t_game_core *game);

#endif