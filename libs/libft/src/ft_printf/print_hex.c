/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 14:49:54 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:56:20 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

static void	write_hex_lower(unsigned int n)
{
	const char	*digits = "0123456789abcdef";
	char		c;

	if (n > 15)
		write_hex_lower(n / 16);
	c = digits[n % 16];
	write(1, &c, 1);
}

static void	write_hex_upper(unsigned int n)
{
	const char	*digits = "0123456789ABCDEF";
	char		c;

	if (n > 15)
		write_hex_upper(n / 16);
	c = digits[n % 16];
	write(1, &c, 1);
}

int	print_hex_upper(unsigned int n)
{
	write_hex_upper(n);
	return (ft_hexlen(n));
}

int	print_hex_lower(unsigned int n)
{
	write_hex_lower(n);
	return (ft_hexlen(n));
}
