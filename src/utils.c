/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/21 16:33:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 14:00:12 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(ft_errno_t ft_errno)
{
	if (ft_errno == FT_SYSTEMFAIL)
		ft_printf_fd(STDERR_FILENO, "Error\n%s\n", strerror(errno));
	else if (ft_errno == FT_INVCHARS)
		ft_printf_fd(STDERR_FILENO, "Error\nMap contains invalid characters\n");
	else if (ft_errno == FT_INVTILENUM)
		ft_printf_fd(STDERR_FILENO, "Error\nMap doesn't contain correct"
			" number of special tiles\n");
	else if (ft_errno == FT_NORECT)
		ft_printf_fd(STDERR_FILENO, "Error\nMap isn't a rectangle\n");
	else if (ft_errno == FT_INVWALLS)
		ft_printf_fd(STDERR_FILENO, "Error\nMap isn't surrounded by walls\n");
	else if (ft_errno == FT_TILEUNREACH)
		ft_printf_fd(STDERR_FILENO, "Error\nUnreachable tiles\n");
	else if (ft_errno == FT_ARGC)
		ft_printf_fd(STDERR_FILENO, "Error\nIncorrect number of arguments\n");
	else if (ft_errno == FT_INVEXT)
		ft_printf_fd(STDERR_FILENO, "Error\nMap is not a .ber file\n");
	else if (ft_errno == FT_MLXFAIL)
		ft_printf_fd(STDERR_FILENO, "Error\n%s\n", mlx_strerror(mlx_errno));
	else if (ft_errno == FT_EMPTY)
		ft_printf_fd(STDERR_FILENO, "Error\nFile is empty\n");
	return (1);
}

char	*remove_nl(char *buf)
{
	char	*tmp;

	tmp = buf;
	buf = ft_strndup(buf, ft_strlen(buf) - 1);
	free(tmp);
	return (buf);
}

void	free_map_data(t_map *map_data, int fd)
{
	ft_free_array(map_data -> map);
	ft_free_array(map_data -> map_fill);
	free (map_data);
	close (fd);
}

int	check_extension(char *arg)
{
	char	*last;

	last = &arg[ft_strlen(arg) - 4];
	return (ft_strcmp(".ber", last));
}

void	bfs_floodfill(t_map *map_data, int x, int y)
{
	if (map_data -> map[y][x] == 'P'
		|| map_data -> map_fill[y][x] == 'C'
		|| map_data -> map_fill[y][x] == '0'
		|| map_data -> map_fill[y][x] == 'E' )
	{
		if (map_data -> map_fill[y][x] == 'C')
			map_data -> coins_reachable++;
		if (map_data -> map_fill[y][x] == 'E')
			map_data -> exit_reachable++;
		map_data -> map_fill[y][x] = 'X';
		bfs_floodfill(map_data, x + 1, y);
		bfs_floodfill(map_data, x - 1, y);
		bfs_floodfill(map_data, x, y + 1);
		bfs_floodfill(map_data, x, y - 1);
	}
}
