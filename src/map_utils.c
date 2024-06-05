/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/22 14:24:54 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 16:28:34 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_horizontal_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_vertical_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_rectangle(char **map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (((int) ft_strlen(map[i])) != width)
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_map_content(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data -> map[i])
	{
		while (map_data -> map[i][j])
		{
			if (map_data -> map[i][j] == 'C')
				map_data -> coins_on_map++;
			if (map_data -> map[i][j] == 'E')
				map_data -> exits_on_map++;
			if (map_data -> map[i][j] == 'P')
				map_data -> players_on_map++;
			j++;
		}
		j = 0;
		i++;
	}
	if (map_data -> coins_on_map < 1 || map_data -> exits_on_map != 1
		|| map_data -> players_on_map != 1)
		return (1);
	return (0);
}
