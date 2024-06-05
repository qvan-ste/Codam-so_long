/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:56:45 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:58:07 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*func_s;

	i = 0;
	func_s = malloc(ft_strlen(s) + 1);
	if (!func_s)
		return (NULL);
	while (s[i])
	{
		func_s[i] = f(i, s[i]);
		i++;
	}
	func_s[i] = '\0';
	return (func_s);
}
