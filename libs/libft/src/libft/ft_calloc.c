/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quincy <quincy@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:17:16 by quincy        #+#    #+#                 */
/*   Updated: 2024/04/17 13:57:06 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*address;

	address = malloc(count * size);
	if (!address)
		return (NULL);
	ft_bzero(address, count * size);
	return (address);
}
