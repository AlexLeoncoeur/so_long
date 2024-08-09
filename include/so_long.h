/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:04:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/09 15:59:19 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*vp = victory points needed to win*/
typedef struct s_game_core
{
	mlx_t		*id;
	char		**map;
	int			vp;
	int			pc_y;
	int			pc_x;
	int			pc_moves;
	int			map_row;
	int			map_w;
	int			map_h;
	float		scale;
	int			offset_x;
	int			offset_y;
	mlx_image_t	*pc_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*rsc_img;
}	t_game_core;

/*-------------------- so_long --------------------*/
void			ft_prepare_game_core(mlx_t *id, t_game_core *game);
void			ft_print_moves(t_game_core *game);
void			ft_load_img(t_game_core *game);
void			ft_win_game(t_game_core *game);

/*-------------------- map --------------------*/
void			ft_resize(int width, int height, void *param);
void			ft_read_map(t_game_core *game, char *map);
void			ft_check_map(t_game_core *game, char c);
void			ft_check_vp(t_game_core *game);
void			ft_render_map(void *param);

/*-------------------- textures --------------------*/
void			ft_load_img(t_game_core *game);

/*-------------------- Controls --------------------*/
void			ft_controls_hook(mlx_key_data_t keydata, void *param);

/*-------------------- Error --------------------*/
void			ft_puterrorstr(char *str, t_game_core *game);
void			ft_exit(t_game_core *game);
void			ft_free(char **str);

#endif