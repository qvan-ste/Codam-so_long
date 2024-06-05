/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdoublast.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 16:00:15 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 16:00:39 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_listdoub	*ft_lstdoublast(t_listdoub *lst)
{
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
