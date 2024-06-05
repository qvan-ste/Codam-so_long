/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_basic_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:32:55 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:56:31 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_fd.h"
#include "../../include/libft.h"

int	print_char_fd(char c, const int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	print_str_fd(char *s, const int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	print_percent_fd(const int fd)
{
	write(fd, "%", 1);
	return (1);
}
