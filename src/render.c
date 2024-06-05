/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 15:00:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 19:05:22 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_t	*draw_window(mlx_t *mlx, t_map *map_data, t_texture *textures)
{
	get_resolution(textures, map_data);
	mlx_terminate(mlx);
	mlx = mlx_init(textures -> window_width,
			textures -> window_height, "So Long", 1);
	if (!mlx)
		error (FT_MLXFAIL);
	return (mlx);
}

void	get_resolution(t_texture *textures, t_map *map_data)
{
	int	max_window_width;
	int	max_window_height;
	int	max_sprite_width;
	int	max_sprite_height;

	mlx_get_monitor_size(0, &max_window_width, &max_window_height);
	max_sprite_width = max_window_width / map_data -> width;
	max_sprite_height = max_window_height / map_data -> height;
	if (max_sprite_width >= max_sprite_height)
		textures -> img_size = max_sprite_height;
	else
		textures -> img_size = max_sprite_width;
	textures -> window_width = textures -> img_size * map_data -> width;
	textures -> window_height = textures -> img_size * map_data -> height;
	textures -> offset = textures -> img_size * 0.15;
}

int	draw_tile(t_gamedata *game_data, char map_char, int y, int x)
{
	int	offset;

	offset = game_data -> textures -> offset;
	if (map_char == '1')
		return (mlx_image_to_window(game_data -> mlx,
				game_data -> textures -> wall_image, x, y));
	else if (map_char == 'C')
		return (mlx_image_to_window(game_data -> mlx,
				game_data -> textures -> coin_image, x + offset, y + offset));
	else if (map_char == 'E')
		return (mlx_image_to_window(game_data -> mlx,
				game_data -> textures -> exit_image, x, y));
	else if (map_char == 'P')
		return (mlx_image_to_window(game_data -> mlx,
				game_data-> textures -> player_image, x + offset, y + offset));
	return (0);
}

int	loop_row(t_gamedata *game_data, char *map_row, int y)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (map_row[i])
	{
		if (draw_tile(game_data, map_row[i], y, x) < 0)
			return (1);
		i++;
		x += game_data -> textures -> img_size;
	}
	return (0);
}

int	draw_map(t_gamedata *game_data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (mlx_image_to_window(game_data -> mlx,
			game_data -> textures -> background_image, 0, 0))
		return (1);
	while (game_data -> map_data -> map[i])
	{
		if (loop_row(game_data, game_data -> map_data -> map[i], y))
			return (1);
		i++;
		y += game_data -> textures -> img_size;
	}
	return (0);
}
