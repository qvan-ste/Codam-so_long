/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:01:33 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:57:38 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;

	if (!dest && !src)
		return (dest);
	char_dest = (char *)dest;
	char_src = (const char *)src;
	while (n)
	{
		char_dest[n - 1] = char_src[n - 1];
		n--;
	}
	return (dest);
}
