/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 20:37:00 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 18:14:38 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_linked_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		free(head -> content);
		head = head -> next;
		free(tmp);
	}
}

int	add_linked_list(t_list *head, int fd)
{
	char	*buf;
	t_list	*node;

	buf = get_next_line(fd);
	if (!buf)
		return (1);
	while (buf)
	{
		if (buf[ft_strlen(buf) - 1] == '\n')
			buf = remove_nl(buf);
		if (!buf)
			return (1);
		node = ft_lstnew(buf);
		if (!node)
			return (free(buf), 1);
		ft_lstadd_back(&head, node);
		buf = get_next_line(fd);
	}
	if (read(fd, buf, 1) < 0)
		return (1);
	return (0);
}
