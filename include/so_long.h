/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:04:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/08/13 15:41:52 by aarenas-         ###   ########.fr       */
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
	bool		exit;
	char		**map;
	char		**map_cpy;
	int			c;
	int			vp;
	int			pc_y;
	int			pc_x;
	int			pc_moves;
	int			map_row;
	size_t		map_column;
	int			map_w;
	int			map_h;
	float		scale;
	int			offset_x;
	int			offset_y;
	mlx_image_t	*pc_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*rsc_img;
	mlx_image_t	*exit_img;
}	t_game_core;

/*-------------------- so_long --------------------*/
void			ft_prepare_game_core(t_game_core *game);
void			ft_print_moves(t_game_core *game);
void			ft_load_img(t_game_core *game);
void			ft_win_game(t_game_core *game);

/*-------------------- map --------------------*/
void			ft_resize(int width, int height, void *param);
void			ft_read_map(t_game_core *game, char *map);
void			ft_check_map(t_game_core *game, char c);
void			ft_check_vp(t_game_core *game);
void			ft_render_map(t_game_core *game);

/*-------------------- textures --------------------*/
void			ft_load_img(t_game_core *game);

/*-------------------- Controls --------------------*/
void			ft_controls_hook(mlx_key_data_t keydata, void *param);

/*-------------------- Error --------------------*/
void			ft_puterrorstr(char *str, t_game_core *game);
void			ft_check_walls(t_game_core *game);
void			ft_exit(t_game_core *game);
void			ft_free(char **str);
int				ft_check_argv(char *argv);

/*-------------------- Utils --------------------*/
void			ft_check_map_component(t_game_core *game);
void			ft_check_map_error(t_game_core *game);
void			ft_flood_prep(t_game_core *game);

/*-------------------- Miscelaneous --------------------*/
void			ft_free_read_map(char *line, char *full_map, t_game_core *game);
void			ft_set_game_core(t_game_core *g);
size_t			ft_len_line(char *str);

#endif