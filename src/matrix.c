/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 20:36:14 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/18 13:07:25 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**make_2d_array(t_list *head)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = malloc (sizeof(char *) * (ft_lstsize(head) + 1));
	if (!matrix)
		return (NULL);
	while (head)
	{
		matrix[i] = ft_strdup(head -> content);
		if (!matrix[i])
			return (NULL);
		head = head -> next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int	map_to_matrix(t_map *map_data, int fd)
{
	char	*buf;
	t_list	*head;

	buf = get_next_line(fd);
	if (!buf)
		return (FT_EMPTY);
	if (buf[ft_strlen(buf) - 1] == '\n')
	{
		buf = remove_nl(buf);
		if (!buf)
			return (FT_SYSTEMFAIL);
	}
	head = ft_lstnew(buf);
	if (!head)
		return (free(buf), FT_SYSTEMFAIL);
	if (add_linked_list(head, fd))
		return (free_linked_list(head), FT_SYSTEMFAIL);
	map_data -> map = make_2d_array(head);
	if (!map_data -> map)
		return (free_linked_list(head), FT_SYSTEMFAIL);
	map_data -> map_fill = make_2d_array(head);
	if (!map_data -> map_fill)
		return (ft_free_array(map_data -> map), free_linked_list(head), 1);
	free_linked_list(head);
	return (0);
}
