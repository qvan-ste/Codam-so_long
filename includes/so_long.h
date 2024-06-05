/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/22 17:13:22 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 14:00:21 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/include/libft.h"

typedef struct t_texture_data
{
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*coin_texture;
	mlx_texture_t	*background_texture;
	mlx_image_t		*wall_image;
	mlx_image_t		*player_image;
	mlx_image_t		*exit_image;
	mlx_image_t		*coin_image;
	mlx_image_t		*background_image;
	int				window_width;
	int				window_height;
	int				img_size;
	int				offset;
}	t_texture;

typedef struct t_map_data
{
	char	**map;
	char	**map_fill;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		coins_on_map;
	int		coins_reachable;
	int		exits_on_map;
	int		exit_reachable;
	int		players_on_map;
}	t_map;

typedef struct t_struct_collection
{
	t_texture	*textures;
	t_map		*map_data;
	mlx_t		*mlx;
	int			coins_collected;
	int			moves;
	int			fd;
}	t_gamedata;

typedef enum ft_errno
{
	FT_SUCCESS,
	FT_SYSTEMFAIL,
	FT_MLXFAIL,
	FT_INVCHARS,
	FT_INVTILENUM,
	FT_NORECT,
	FT_INVWALLS,
	FT_TILEUNREACH,
	FT_INVEXT,
	FT_ARGC,
	FT_EMPTY,

}	ft_errno_t;

int			add_linked_list(t_list *head, int fd);
char		**make_2d_array(t_list *head);
int			map_to_matrix(t_map *map_data, int fd);
void		free_linked_list(t_list *head);
int			check_horizontal_walls(char **map, int height, int width);
int			check_vertical_walls(char **map, int height, int width);
int			check_map(t_map *map_data);
int			check_rectangle(char **map, int width);
char		*remove_nl(char *buf);
int			check_valid_chars(char **map);
int			check_map_content(t_map *map_data);
void		bfs_floodfill(t_map *map, int x, int y);
t_map		*init_map_data(t_map *map_data, int width, int height);
int 		init_mlx(t_map *map_data, t_gamedata **gamedata, int fd);
int			create_textures(t_texture *textures);
int			create_images(mlx_t *mlx, t_texture *textures);
int			resize_images(t_texture *textures);
int			init_map(t_gamedata * game_data);
void		get_resolution(t_texture *textures, t_map *map_data);
int			loop_row(t_gamedata *game_data, char *map_row, int y);
int			draw_tile(t_gamedata *game_data, char map_char, int y, int x);
int			draw_map(t_gamedata *game_data);
void 		init_norm_vars(t_gamedata *game_data, int *player_x, int *player_y, int *offset);
void 		move_player(mlx_key_data_t keydata, void* param);
int			init_game(t_gamedata *game_data);
int			error(ft_errno_t ft_errno);
int			check_extension(char *arg);
void		free_game_data(t_gamedata *game_data);
void		free_map_data(t_map *map_data, int fd);
t_map		*read_map(int fd);
mlx_t		*draw_window(mlx_t *mlx, t_map *map_data, t_texture *textures);
t_gamedata	*init_game_data(mlx_t *mlx, t_texture *textures, t_map *map_data, int fd);
int			check_collision(t_gamedata *game_data, int n_player_x, int n_player_y);
int			exit_collision(t_gamedata *game_data, int n_player_x, int n_player_y);
void		coin_collision(t_gamedata *game_data, int n_player_x, int n_player_y);
int			wall_collision(t_gamedata *game_data, int n_player_x, int n_player_y);

#endif
