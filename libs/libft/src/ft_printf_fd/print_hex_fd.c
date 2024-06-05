/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 14:49:54 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:56:38 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_fd.h"
#include "../../include/libft.h"

static void	write_hex_lower_fd(unsigned int n, const int fd)
{
	const char	*digits = "0123456789abcdef";
	char		c;

	if (n > 15)
		write_hex_lower_fd((n / 16), fd);
	c = digits[n % 16];
	write(fd, &c, 1);
}

static void	write_hex_upper_fd(unsigned int n, const int fd)
{
	const char	*digits = "0123456789ABCDEF";
	char		c;

	if (n > 15)
		write_hex_upper_fd((n / 16), fd);
	c = digits[n % 16];
	write(fd, &c, 1);
}

int	print_hex_upper_fd(unsigned int n, const int fd)
{
	write_hex_upper_fd(n, fd);
	return (ft_hexlen(n));
}

int	print_hex_lower_fd(unsigned int n, const int fd)
{
	write_hex_lower_fd(n, fd);
	return (ft_hexlen(n));
}
