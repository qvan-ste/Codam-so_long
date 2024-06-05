/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/22 17:19:55 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 20:17:05 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*read_map(int fd)
{
	t_map		*map_data;
	int			width;
	int			height;
	ft_errno_t	ft_errno;

	height = 0;
	map_data = malloc(sizeof (t_map));
	if (!map_data)
		return (NULL);
	ft_errno = map_to_matrix(map_data, fd);
	if (ft_errno)
	{
		error(ft_errno);
		free (map_data);
		return (NULL);
	}
	while (map_data -> map[height])
		height++;
	width = ft_strlen(map_data -> map[0]);
	map_data = init_map_data(map_data, width, height);
	return (map_data);
}

int	check_map(t_map *map_data)
{
	if (check_valid_chars(map_data -> map))
		return (error(FT_INVCHARS));
	if (check_map_content(map_data))
		return (error(FT_INVTILENUM));
	if (check_rectangle(map_data -> map, map_data -> width))
		return (error(FT_NORECT));
	if (check_horizontal_walls(map_data -> map, map_data -> height,
			map_data -> width) || check_vertical_walls(map_data -> map,
			map_data -> height, map_data -> width))
		return (error(FT_INVWALLS));
	bfs_floodfill(map_data, map_data -> start_x, map_data -> start_y);
	if (map_data -> coins_on_map != map_data -> coins_reachable
		|| map_data -> exit_reachable != 1)
		return (error(FT_TILEUNREACH));
	return (0);
}

void	get_starting_coords(t_map *map_data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map_data -> map[i])
	{
		if (ft_strchr(map_data -> map[i], 'P'))
		{
			map_data -> start_y = i;
			map_data -> start_x
				= (ft_strchr(map_data -> map[i], 'P')) - (map_data -> map[i]);
		}
		i++;
	}
}

t_map	*init_map_data(t_map *map_data, int width, int height)
{
	map_data -> width = width;
	map_data -> height = height;
	map_data -> coins_reachable = 0;
	map_data -> exit_reachable = 0;
	map_data -> coins_on_map = 0;
	map_data -> players_on_map = 0;
	map_data -> exits_on_map = 0;
	get_starting_coords(map_data);
	return (map_data);
}
