/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/17 15:27:37 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 19:48:54 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wall_collision(t_gamedata *game_data, int n_player_x, int n_player_y)
{
	size_t	i;
	int		wall_x;
	int		wall_y;

	i = 0;
	while (i < game_data -> textures -> wall_image -> count)
	{
		wall_x = game_data -> textures -> wall_image -> instances[i].x;
		wall_y = game_data -> textures -> wall_image -> instances[i].y;
		if ((n_player_x == wall_x && n_player_y == wall_y))
			return (1);
		i++;
	}
	return (0);
}

void	coin_collision(t_gamedata *game_data, int n_player_x, int n_player_y)
{
	size_t	i;
	int		coin_x;
	int		coin_y;
	int		coin_enabled;
	int		offset;

	i = 0;
	offset = game_data -> textures -> offset;
	while (i < game_data -> textures -> coin_image -> count)
	{
		coin_x = game_data -> textures -> coin_image -> instances[i].x - offset;
		coin_y = game_data -> textures -> coin_image -> instances[i].y - offset;
		coin_enabled = game_data -> textures -> coin_image
			-> instances[i].enabled;
		if (coin_enabled && n_player_x == coin_x && n_player_y == coin_y)
		{
			game_data -> coins_collected++;
			game_data -> textures -> coin_image -> instances[i].enabled = 0;
		}
		i++;
	}
}

int	exit_collision(t_gamedata *game_data, int n_player_x, int n_player_y)
{
	int		exit_x;
	int		exit_y;

	exit_x = game_data -> textures -> exit_image -> instances[0].x;
	exit_y = game_data -> textures -> exit_image -> instances[0].y;
	if ((n_player_x == exit_x && n_player_y == exit_y)
		&& game_data -> coins_collected
		== game_data -> map_data -> coins_on_map)
	{
		game_data -> textures -> player_image -> instances[0].x = exit_x;
		game_data -> textures -> player_image -> instances[0].y = exit_y;
		return (ft_printf("Winner!\n"));
	}
	return (0);
}

int	check_collision(t_gamedata *game_data, int n_player_x, int n_player_y)
{
	if (wall_collision(game_data, n_player_x, n_player_y))
		return (1);
	coin_collision(game_data, n_player_x, n_player_y);
	if (exit_collision(game_data, n_player_x, n_player_y))
	{
		mlx_terminate(game_data -> mlx);
		free_game_data(game_data);
		exit(0);
	}
	game_data -> moves++;
	ft_printf("Moves: %i\n", game_data -> moves);
	return (0);
}
