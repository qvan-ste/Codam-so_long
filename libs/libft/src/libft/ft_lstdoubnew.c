/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdoubnew.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 16:00:58 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 16:01:11 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_listdoub	*ft_lstdoubnew(void *content)
{
	t_listdoub	*new;

	new = malloc(sizeof(t_listdoub));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> prev = NULL;
	new -> next = NULL;
	return (new);
}
