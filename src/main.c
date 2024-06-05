/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 18:53:25 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/29 13:21:32 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game_data(t_gamedata *game_data)
{
	close (game_data -> fd);
	free(game_data -> textures -> wall_texture);
	free(game_data -> textures -> player_texture);
	free(game_data -> textures -> exit_texture);
	free(game_data -> textures -> coin_texture);
	free(game_data -> textures -> background_texture);
	free(game_data -> textures);
	ft_free_array(game_data -> map_data -> map);
	ft_free_array(game_data -> map_data -> map_fill);
	free (game_data -> map_data);
	free (game_data);
}

int	init_mlx(t_map *map_data, t_gamedata **game_data, int fd)
{
	mlx_t		*mlx;
	t_texture	*textures;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	textures = malloc(sizeof(t_texture));
	if (!textures)
		return (error(FT_SYSTEMFAIL));
	mlx = mlx_init(1, 1, "Window", true);
	if (!mlx)
		return (free(textures), error(FT_MLXFAIL));
	mlx = draw_window(mlx, map_data, textures);
	if (!mlx)
		return (free(textures), 1);
	*game_data = init_game_data(mlx, textures, map_data, fd);
	if (!game_data)
		return (free(textures), 1);
	if (init_map(*game_data))
		return (free_game_data(*game_data), 1);
	return (0);
}

int	init_map(t_gamedata *game_data)
{
	if (create_textures(game_data -> textures))
		return (error(FT_MLXFAIL));
	if (create_images(game_data -> mlx, game_data -> textures))
		return (error(FT_MLXFAIL));
	if (resize_images(game_data -> textures))
		return (error(FT_MLXFAIL));
	if (draw_map(game_data))
		return (error(FT_MLXFAIL));
	return (0);
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_map		*map_data;
	t_gamedata	*game_data;

	if (argc != 2)
		return (error(FT_ARGC));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error(FT_SYSTEMFAIL));
	if (check_extension(argv[1]))
		return (close(fd), error(FT_INVEXT));
	map_data = read_map(fd);
	if (!map_data)
		return (close(fd), 1);
	if (check_map(map_data))
		return (free_map_data(map_data, fd), 1);
	if (init_mlx(map_data, &game_data, fd))
		return (free_map_data(map_data, fd), 1);
	init_game(game_data);
	free_game_data(game_data);
	exit (1);
}
