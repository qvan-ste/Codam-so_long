/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interaction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 18:41:09 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/29 14:43:03 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_gamedata	*init_game_data(mlx_t *mlx, t_texture *textures,
	t_map *map_data, int fd)
{
	t_gamedata	*game_data;

	game_data = malloc(sizeof(t_gamedata));
	if (!game_data)
	{
		error(FT_SYSTEMFAIL);
		return (NULL);
	}
	game_data -> mlx = mlx;
	game_data -> textures = textures;
	game_data -> map_data = map_data;
	game_data -> coins_collected = 0;
	game_data -> moves = 0;
	game_data -> fd = fd;
	return (game_data);
}

int	init_game(t_gamedata *game_data)
{
	mlx_t	*mlx;

	mlx = game_data -> mlx;
	mlx_key_hook(mlx, &move_player, game_data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_printf_fd(STDERR_FILENO, "Program interrupted\n");
	return (0);
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_gamedata	*game_data;
	int			img_size;
	int			player_x;
	int			player_y;
	int			offset;

	(void)keydata;
	game_data = param;
	img_size = game_data -> textures -> img_size;
	init_norm_vars(game_data, &player_x, &player_y, &offset);
	if (mlx_is_key_down(game_data -> mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_data -> mlx);
	if (mlx_is_key_down(game_data -> mlx, MLX_KEY_W)
		&& !check_collision(game_data, player_x, player_y - img_size))
		game_data -> textures -> player_image -> instances[0].y -= img_size;
	if (mlx_is_key_down(game_data -> mlx, MLX_KEY_S)
		&& !check_collision(game_data, player_x, player_y + img_size))
		game_data -> textures -> player_image -> instances[0].y += img_size;
	if (mlx_is_key_down(game_data -> mlx, MLX_KEY_A)
		&& !check_collision(game_data, player_x - img_size, player_y))
		game_data -> textures -> player_image -> instances[0].x -= img_size;
	if (mlx_is_key_down(game_data -> mlx, MLX_KEY_D)
		&& !check_collision(game_data, player_x + img_size, player_y))
		game_data -> textures -> player_image -> instances[0].x += img_size;
}

void	init_norm_vars(t_gamedata *game_data,
	int *player_x, int *player_y, int *offset)
{
	*offset = game_data -> textures -> offset;
	*player_x = game_data -> textures
		-> player_image -> instances[0].x - *offset;
	*player_y = game_data -> textures
		-> player_image -> instances[0].y - *offset;
}
