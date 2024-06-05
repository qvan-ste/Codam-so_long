/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_num_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:36:20 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:56:41 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <limits.h>

int	print_num_fd(int n, const int fd)
{
	ft_putnbr_fd(n, fd);
	return (ft_intlen(n) + (n < 0));
}

int	print_unsigned_fd(long n, const int fd)
{
	if (n < 0)
		n = UINT_MAX - -n;
	ft_putnbr_fd(n, fd);
	return (ft_intlen(n));
}
