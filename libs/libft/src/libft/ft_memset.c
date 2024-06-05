/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:35:34 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:57:46 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*char_s;
	size_t			i;

	char_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		char_s[i] = c;
		i++;
	}
	return (s);
}
